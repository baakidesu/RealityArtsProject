// Copyright baakidesu


#include "Player/InternPlayerController.h"

#include "Blueprint/UserWidget.h"
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

	OverlayWidget = CreateWidget<UUserWidget>(GetWorld(), OverlayWidgetClass);
	if (!OverlayWidget) return;
	OverlayWidget->AddToViewport(0);

	if (AInternGameState* GS = GetWorld() ? GetWorld()->GetGameState<AInternGameState>() : nullptr)
	{
		GS->OnUpgradeUnlocked.AddDynamic(this, &AInternPlayerController::CreateUpgradeWidget);
	}
	
}

void AInternPlayerController::CreateUpgradeWidget()
{
	if (UpgradeWidgetClass == nullptr) return;

	UpgradeWidget = CreateWidget<UUserWidget>(GetWorld(), UpgradeWidgetClass);
	OverlayWidget->SetVisibility(ESlateVisibility::Hidden);

	FocusWidget(UpgradeWidget, true);
}

void AInternPlayerController::FocusWidget(UUserWidget* WidgetToFocus, bool bPauseGame)
{
	WidgetToFocus->AddToViewport();
	WidgetToFocus->SetVisibility(ESlateVisibility::Visible);
	FInputModeUIOnly InputMode;
	InputMode.SetWidgetToFocus(WidgetToFocus->TakeWidget()); 
	InputMode.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock); 

	SetInputMode(InputMode);
	bShowMouseCursor = true;
	SetPause(bPauseGame);
}

void AInternPlayerController::UnfocusWidget(UUserWidget* WidgetToUnfocus)
{
	WidgetToUnfocus->RemoveFromParent();
	WidgetToUnfocus = nullptr;

	FInputModeGameOnly Mode;
	SetInputMode(Mode);

	bShowMouseCursor = false;
	SetPause(false);
}

void AInternPlayerController::UnfocusUpgradeWidget()
{
	if (UpgradeWidget == nullptr && OverlayWidget == nullptr) return;
	FocusWidget(OverlayWidget, false);
	UnfocusWidget(UpgradeWidget);
}

