// Copyright baakidesu


#include "Spells/InternProjectile.h"
#include "NiagaraComponent.h"
#include "NiagaraFunctionLibrary.h"
#include "Components/SphereComponent.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
AInternProjectile::AInternProjectile()
{
	PrimaryActorTick.bCanEverTick = false;

	SphereComponent = CreateDefaultSubobject<USphereComponent>(FName("Sphere Component"));
	SphereComponent->SetSphereRadius(5.11f);

	NiagaraComponent = CreateDefaultSubobject<UNiagaraComponent>(TEXT("Niagara Component"));
	NiagaraComponent->SetupAttachment(SphereComponent);
	
	ProjectileMove = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Projectile Movement"));
	ProjectileMove->InitialSpeed = InitialOrbSpeed;
	ProjectileMove->MaxSpeed = MaxOrbSpeed;
	ProjectileMove->ProjectileGravityScale = 0.f;
	
}

void AInternProjectile::BeginPlay()
{
	Super::BeginPlay();
	SetLifeSpan(LifeSpan);
}

void AInternProjectile::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);

	if (ProjectileTraceNiagaraEffect)
	{
		NiagaraComponent->SetAsset(ProjectileTraceNiagaraEffect);
		NiagaraComponent->Activate(true);
	}
}

void AInternProjectile::DestroyNiagaraSystems()
{
	check(ProjectileTraceNiagaraEffect);
	NiagaraComponent->DestroyComponent();
}

void AInternProjectile::PlaySoundEffect()
{
	if (SuccessfulSound && SuccessfulHit)
	{
		UGameplayStatics::PlaySoundAtLocation(GetWorld(), SuccessfulSound, GetActorLocation());

	}
	else if (FailSound)
	{
		UGameplayStatics::PlaySoundAtLocation(GetWorld(), FailSound, GetActorLocation());
	}
}

bool AInternProjectile::CanHitToTarget()
{
	if (ActorHasTag(TargetActorTag) && CanThisOrbHit)
	{
		return true;
	}
	
	return false;
}

void AInternProjectile::BeginOverlap(AActor* OtherActor)
{
	if (!CanThisOrbHit) return;
	if (OtherActor->ActorHasTag(TargetActorTag))
	{
		SuccessfulHit = true;
	}
	DestroyNiagaraSystems();
	UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(), StandartHitNiagaraEffect, GetActorLocation(), FRotator(0, 0, 0));
	PlaySoundEffect();
}
