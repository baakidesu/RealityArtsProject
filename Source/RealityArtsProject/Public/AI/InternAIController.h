// Copyright baakidesu

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "InternAIController.generated.h"

/**
 * 
 */
UCLASS()
class REALITYARTSPROJECT_API AInternAIController : public AAIController
{
	GENERATED_BODY()

	AInternAIController();

public:
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
	TObjectPtr<UBehaviorTreeComponent> BehaviorTreeComp;
};
