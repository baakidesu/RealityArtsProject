// Copyright baakidesu


#include "Character/InternEnemy.h"
#include "Components/WidgetComponent.h"


AInternEnemy::AInternEnemy()
{
	HealthBarWidget = CreateDefaultSubobject<UWidgetComponent>(TEXT("HealthBarWidget"));
	HealthBarWidget->SetupAttachment(GetRootComponent());
}

void AInternEnemy::Die()
{
	SetLifeSpan(5.f);

	OnDeath.Broadcast(this);
	Super::Die();
}