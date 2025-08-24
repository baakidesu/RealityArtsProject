// Copyright baakidesu


#include "Player/InternPlayerController.h"

#include "Blueprint/WidgetBlueprintLibrary.h"
#include "Game/InternGameState.h"
#include "Widget/InternHUD.h"

void AInternPlayerController::SendGameOverInformationToHUD(bool DidWin)
{
	if (AInternHUD* HUD = GetHUD<AInternHUD>())
	{
		HUD->HandleEndGameWidget(DidWin);
	}
}

void AInternPlayerController::BeginPlay()
{
	Super::BeginPlay();

	if (AInternGameState* GS = GetWorld()->GetGameState<AInternGameState>())
	{
		GS->OnGameEnds.AddDynamic(this, &AInternPlayerController::SendGameOverInformationToHUD);
	}
}
