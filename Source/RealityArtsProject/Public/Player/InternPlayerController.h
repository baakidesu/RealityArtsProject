// Copyright baakidesu

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Interaction/CombatInterface.h"
#include "InternPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class REALITYARTSPROJECT_API AInternPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	
	UFUNCTION()
	void SendGameOverInformationToHUD(bool DidWin);

	virtual void BeginPlay() override;

};
