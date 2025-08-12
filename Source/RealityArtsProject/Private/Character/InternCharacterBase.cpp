// Copyright baakidesu

#include "Character/InternCharacterBase.h"
#include "GameplayEffectTypes.h"
#include "AbilitySystemComponent.h"
#include "AbilitySystem/InternAttributeSet.h"
#include "Components/CapsuleComponent.h"

AInternCharacterBase::AInternCharacterBase()
{
	PrimaryActorTick.bCanEverTick = false;

	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
	AttributeSet = CreateDefaultSubobject<UInternAttributeSet>(TEXT("AttributeSet"));

	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>("Weapon");
	Weapon->SetupAttachment(GetMesh(), FName("WeaponHandSocket"));
	Weapon->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

UAbilitySystemComponent* AInternCharacterBase::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

void AInternCharacterBase::Die()
{
	//TODO: Maintance Weapon Ragdoll

	Weapon->DestroyComponent();
	
	/*
	Weapon->DetachFromComponent(FDetachmentTransformRules(EDetachmentRule::KeepWorld, true));
	Weapon->SetSimulatePhysics(true);
	Weapon->SetEnableGravity(true);
	Weapon->SetCollisionEnabled(ECollisionEnabled::PhysicsOnly);*/

	GetMesh()->SetSimulatePhysics(true);
	GetMesh()->SetEnableGravity(true);
	GetMesh()->SetCollisionEnabled(ECollisionEnabled::PhysicsOnly);
	GetMesh()->SetCollisionResponseToChannel(ECC_WorldStatic, ECR_Block);

	GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

void AInternCharacterBase::HandleHealthChanged(const FOnAttributeChangeData& Data)
{
	OnHealthChanged.Broadcast(Data.NewValue); // Send value to widget
}

void AInternCharacterBase::HandleManaChanged(const FOnAttributeChangeData& Data)
{
	OnManaChanged.Broadcast(Data.NewValue); // Send value to widget
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