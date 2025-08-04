// Fill out your copyright notice in the Description page of Project Settings.

#include "Character/InternCharacterBase.h"
#include "GameplayEffectTypes.h"
#include "AbilitySystemComponent.h"
#include "AbilitySystem/InternAttributeSet.h"

AInternCharacterBase::AInternCharacterBase()
{
	PrimaryActorTick.bCanEverTick = false;

	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
	AttributeSet = CreateDefaultSubobject<UInternAttributeSet>(TEXT("AttributeSet"));

}

UAbilitySystemComponent* AInternCharacterBase::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}


void AInternCharacterBase::HandleHealthChanged(const FOnAttributeChangeData& Data)
{
	OnHealthChanged.Broadcast(Data.NewValue); // Widget'a gider

}

void AInternCharacterBase::HandleManaChanged(const FOnAttributeChangeData& Data)
{
	OnManaChanged.Broadcast(Data.NewValue); // Widget'a gider
}

void AInternCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
	if (AbilitySystemComponent)
	{
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
			AttributeSet->GetHealthAttribute()
		).AddUObject(this, &AInternCharacterBase::HandleHealthChanged);

		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
			AttributeSet->GetManaAttribute()
		).AddUObject(this, &AInternCharacterBase::HandleManaChanged);
	}
}
