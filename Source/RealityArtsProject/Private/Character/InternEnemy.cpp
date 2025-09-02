// Copyright baakidesu


#include "Character/InternEnemy.h"
#include "Components/WidgetComponent.h"


AInternEnemy::AInternEnemy()
{
	HealthBarWidget = CreateDefaultSubobject<UWidgetComponent>(TEXT("HealthBarWidget"));
	HealthBarWidget->SetupAttachment(GetRootComponent());
}

void AInternEnemy::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	if (!HasAuthority()) return;

	AIController = Cast<AInternAIController>(NewController);
	if (AIController)
	{
		AIController->GetBlackboardComponent()->InitializeBlackboard(*BehaviorTree->GetBlackboardAsset());
		AIController->RunBehaviorTree(BehaviorTree);

		AIController->GetBlackboardComponent()->SetValueAsBool(FName("RangedAttacker"), IsRangedAttacker);
	}
	
}

void AInternEnemy::Die()
{
	SetLifeSpan(5.f);

	OnDeath.Broadcast(this);
	Super::Die();
}
