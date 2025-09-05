// Copyright baakidesu

#pragma once

#include "GameplayEffectTypes.h"
#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "AbilitySystemComponent.h"
#include "AbilitySystem/InternAttributeSet.h"
#include "GameFramework/Character.h"
#include "Interaction/CombatInterface.h"
#include "InternCharacterBase.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHealthChangedSignature, float, NewHealth);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnManaChangedSignature, float, NewMana);

UCLASS()
class REALITYARTSPROJECT_API AInternCharacterBase : public ACharacter, public IAbilitySystemInterface, public ICombatInterface
{
	GENERATED_BODY()

public:
	AInternCharacterBase();

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	UPROPERTY(BlueprintAssignable, Category= "C++ | Attributes")
	FOnHealthChangedSignature OnHealthChanged;

	UPROPERTY(BlueprintAssignable, Category= "C++ | Attributes")
	FOnHealthChangedSignature OnManaChanged;

	UPROPERTY(BlueprintAssignable, Category= "C++ | Attributes")
	FOnHealthChangedSignature OnWalkSpeedChanged;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "C++ | GAS")
	TMap<TSubclassOf<UGameplayEffect>, FGameplayTag> BaseAttributesToApply;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "C++ | GAS")
	TMap<TSubclassOf<UGameplayAbility>, FGameplayTag> BaseAbilitiesToGive;

protected:
	virtual void BeginPlay() override;

	void ApplyEffectToSelf(TSubclassOf<UGameplayEffect> GameplayEffectClass, float Level) const;

	/* Combat Interface */
	virtual void Die() override;

	void HandleHealthChanged(const FOnAttributeChangeData& Data);
	void HandleManaChanged(const FOnAttributeChangeData& Data);
	void HandleWalkSpeedChanged(const FOnAttributeChangeData& Data);
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "C++ | GAS")
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;
	
	UPROPERTY()
	TObjectPtr<UInternAttributeSet> AttributeSet;

	UPROPERTY(EditAnywhere, Category="C++ | Combat")
	TObjectPtr<USkeletalMeshComponent> Weapon;

	UPROPERTY(BlueprintReadOnly, Category = "C++ | Combat")
	bool bIsAlive = true;

	UPROPERTY(BlueprintReadOnly, Category = "C++ | Character")
	float WalkSpeed;
};
