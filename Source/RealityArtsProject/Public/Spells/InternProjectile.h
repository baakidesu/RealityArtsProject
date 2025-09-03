// Copyright baakidesu

#pragma once

#include "CoreMinimal.h"
#include "NiagaraComponent.h"
#include "Components/SphereComponent.h"
#include "GameFramework/Actor.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "InternProjectile.generated.h"

UCLASS()
class REALITYARTSPROJECT_API AInternProjectile : public AActor
{
	GENERATED_BODY()
	
public:	

	AInternProjectile();

	virtual void BeginPlay() override;
	virtual void OnConstruction(const FTransform& Transform) override;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Properties | Sound")
	USoundBase* SuccessfulSound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Properties | Sound")
	USoundBase* FailSound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Properties | Niagara")
	UNiagaraSystem* StandartHitNiagaraEffect;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Properties | Niagara")
	UNiagaraSystem* SuccessfulHitNiagaraEffect;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Properties | Niagara")
	UNiagaraSystem* ProjectileTraceNiagaraEffect;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Properties | Orb")
	float LifeSpan;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Properties | Orb")
	USphereComponent* SphereComponent;

	UPROPERTY(BlueprintReadWrite, Category = "Properties | Orb")
	bool CanThisOrbHit = true;

	UPROPERTY(BlueprintReadWrite, Category = "Properties | Orb")
	bool SuccessfulHit = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Properties | Orb")
	FName TargetActorTag;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Properties | Orb")
	float InitialOrbSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Properties | Orb")
	float MaxOrbSpeed;

protected:

	UFUNCTION()
	void DestroyNiagaraSystems();

	UFUNCTION()
	void PlaySoundEffect();

	UFUNCTION()
	bool CanHitToTarget();
	
	UFUNCTION(BlueprintCallable)
	void BeginOverlap(AActor* OtherActor);
	
	UPROPERTY()
	UNiagaraComponent* NiagaraComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components")
	UProjectileMovementComponent* ProjectileMove;
};
