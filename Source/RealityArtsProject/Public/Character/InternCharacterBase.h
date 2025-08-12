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

	UPROPERTY(BlueprintAssignable, Category = "Attributes")
	FOnHealthChangedSignature OnHealthChanged;

	UPROPERTY(BlueprintAssignable, Category = "Attributes")
	FOnHealthChangedSignature OnManaChanged;
	
	/* Combat Interface */
	virtual void Die() override;

protected:
	virtual void BeginPlay() override;

	void HandleHealthChanged(const FOnAttributeChangeData& Data);
	void HandleManaChanged(const FOnAttributeChangeData& Data);
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Abilities")
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY()
	TObjectPtr<UInternAttributeSet> AttributeSet;

	UPROPERTY(EditAnywhere, Category="Combat")
	TObjectPtr<USkeletalMeshComponent> Weapon;
};
