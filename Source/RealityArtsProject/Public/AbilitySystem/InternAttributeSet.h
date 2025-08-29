// Copyright baakidesu

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "AttributeSet.h"
#include "InternAttributeSet.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

/**
 * 
 */
UCLASS()
class REALITYARTSPROJECT_API UInternAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

public:
	UInternAttributeSet();

	UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing = OnRep_Health, Category= "Attributes")
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(UInternAttributeSet, Health);

	UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing = OnRep_MaxHealth, Category= "Attributes")
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(UInternAttributeSet, MaxHealth);

	UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing = OnRep_Mana, Category= "Attributes")
	FGameplayAttributeData Mana;
	ATTRIBUTE_ACCESSORS(UInternAttributeSet, Mana);

	UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing = OnRep_MaxMana, Category= "Attributes")
	FGameplayAttributeData MaxMana;
	ATTRIBUTE_ACCESSORS(UInternAttributeSet, MaxMana);

	UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing = OnRep_WalkSpeed, Category= "Attributes")
	FGameplayAttributeData WalkSpeed;
	ATTRIBUTE_ACCESSORS(UInternAttributeSet, WalkSpeed);

	UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing = OnRep_HealthRegen, Category= "Attributes")
	FGameplayAttributeData HealthRegen;
	ATTRIBUTE_ACCESSORS(UInternAttributeSet, HealthRegen);

	UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing = OnRep_ManaRegen, Category= "Attributes")
	FGameplayAttributeData ManaRegen;
	ATTRIBUTE_ACCESSORS(UInternAttributeSet, ManaRegen);
	
	UPROPERTY(BlueprintReadOnly, Category="Meta Attributes")
	FGameplayAttributeData IncomingDamage;
	ATTRIBUTE_ACCESSORS(UInternAttributeSet, IncomingDamage);

protected:

	void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue);
	void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data);

	UFUNCTION()
	void OnRep_Health(const FGameplayAttributeData& OldHealth);

	UFUNCTION()
	void OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth);

	UFUNCTION()
	void OnRep_Mana(const FGameplayAttributeData& OldMana);

	UFUNCTION()
	void OnRep_MaxMana(const FGameplayAttributeData& OldMaxMana);

	UFUNCTION()
	void OnRep_WalkSpeed(const FGameplayAttributeData& OldWalkSpeed);

	UFUNCTION()
	void OnRep_HealthRegen(const FGameplayAttributeData& OldHealthRegen);

	UFUNCTION()
	void OnRep_ManaRegen(const FGameplayAttributeData& OldManaRegen);
};
