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
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "C++ | Properties | Sound")
	USoundBase* SuccessfulSound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "C++ | Properties | Sound")
	USoundBase* FailSound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "C++ | Properties | Niagara")
	UNiagaraSystem* StandartHitNiagaraEffect;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "C++ | Properties | Niagara")
	UNiagaraSystem* SuccessfulHitNiagaraEffect;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "C++ | Properties | Niagara")
	UNiagaraSystem* ProjectileTraceNiagaraEffect;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "C++ | Properties | Orb")
	float LifeSpan;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "C++ | Properties | Orb")
	USphereComponent* SphereComponent;

	UPROPERTY(BlueprintReadWrite, Category = "C++ | Properties | Orb")
	bool CanThisOrbHit = true;

	UPROPERTY(BlueprintReadWrite, Category = "C++ | Properties | Orb")
	bool SuccessfulHit = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "C++ | Properties | Orb")
	FName TargetActorTag;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "C++ | Properties | Orb")
	float InitialOrbSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "C++ | Properties | Orb")
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

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="C++ | Components")
	UProjectileMovementComponent* ProjectileMove;
};
