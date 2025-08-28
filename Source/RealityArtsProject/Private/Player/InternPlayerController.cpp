// Copyright baakidesu


#include "Player/InternPlayerController.h"

#include "Blueprint/WidgetBlueprintLibrary.h"
#include "Game/InternGameState.h"
#include "Kismet/GameplayStatics.h"

void AInternPlayerController::CreateGameOverWidget(bool DidWin)
{
	if (!WinWidgetClass || !LoseWidgetClass) return;
	TSubclassOf<UUserWidget> WidgetToCreate = DidWin ? WinWidgetClass : LoseWidgetClass;

	TArray<UUserWidget*> FoundWidgets;
	UWidgetBlueprintLibrary::GetAllWidgetsOfClass(GetWorld(), FoundWidgets, UUserWidget::StaticClass(), false);
	for (UUserWidget* Widget : FoundWidgets)
	{
		if (Widget)
		{
			Widget->RemoveFromParent();
		}
	}
	
	UUserWidget* EndGameWidget = CreateWidget<UUserWidget>(GetWorld(), WidgetToCreate);
	EndGameWidget->AddToViewport(0);
	SetShowMouseCursor(true);
	UGameplayStatics::SetGamePaused(GetWorld(),true);
}

void AInternPlayerController::BeginPlay()
{
	Super::BeginPlay();

	if (AInternGameState* GS = GetWorld()->GetGameState<AInternGameState>())
	{
		GS->OnGameEnds.AddDynamic(this, &AInternPlayerController::CreateGameOverWidget);
	}

	UUserWidget* OverlayWidget = CreateWidget<UUserWidget>(GetWorld(), OverlayWidgetClass);
	if (!OverlayWidget) return;
	OverlayWidget->AddToViewport(0);
	
}
