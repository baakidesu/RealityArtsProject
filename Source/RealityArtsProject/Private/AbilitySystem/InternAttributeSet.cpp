// Copyright baakidesu


#include "AbilitySystem/InternAttributeSet.h"

#include "GameplayEffectExtension.h"
#include "Character/InternCharacterBase.h"
#include "Net/UnrealNetwork.h"

UInternAttributeSet::UInternAttributeSet()
{
	 InitHealth(100);
	 InitMana(100);
}

void UInternAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION_NOTIFY(UInternAttributeSet, Health, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UInternAttributeSet, Mana, COND_None, REPNOTIFY_Always);
}

void UInternAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	Super::PreAttributeChange(Attribute, NewValue);

	if (Attribute == GetHealthAttribute())
	{
		NewValue = FMath::Clamp<float>(NewValue, 0.0f, 100);
	}
	
	if (Attribute == GetManaAttribute())
	{
		NewValue = FMath::Clamp<float>(NewValue, 0.0f, 100);
	}
}

void UInternAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);
	
	if (Data.EvaluatedData.Attribute == GetHealthAttribute())
	{
		SetHealth(FMath::Clamp(GetHealth(),0.f,100));
	}

	if (Data.EvaluatedData.Attribute == GetManaAttribute())
	{
		SetMana(FMath::Clamp(GetMana(),0.f,100));
	}
 
	if (Data.EvaluatedData.Attribute == GetIncomingDamageAttribute())
	{
		const float LocalIncomingDamage = GetIncomingDamage();
		SetIncomingDamage(0.f);
		if (LocalIncomingDamage > 0)
		{
			const float NewHealth = GetHealth() - LocalIncomingDamage;
			SetHealth(FMath::Clamp(NewHealth,0.f,100));

			const bool bFatal = NewHealth <= 0.f;

			if (bFatal)
			{
				ICombatInterface* CombatInterface = Cast<ICombatInterface>(Data.Target.AbilityActorInfo->AvatarActor.Get());

				if (CombatInterface)
				{
					CombatInterface->Die();
				}
			}

			else
			{
				FGameplayTagContainer TagContainer;
			}
		}
	}
}

void UInternAttributeSet::OnRep_Health(const FGameplayAttributeData& OldHealth)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UInternAttributeSet, Health, OldHealth);
}

void UInternAttributeSet::OnRep_Mana(const FGameplayAttributeData& OldMana)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UInternAttributeSet, Mana, OldMana);
}