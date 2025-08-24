// Copyright baakidesu


#include "Widget/InternHUD.h"

#include "Blueprint/UserWidget.h"
#include "Blueprint/WidgetBlueprintLibrary.h"
#include "Kismet/GameplayStatics.h"

void AInternHUD::HandleEndGameWidget(bool DidWin)
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
	GetOwningPlayerController()->SetShowMouseCursor(true);
	UGameplayStatics::SetGamePaused(GetWorld(),true);
	
}
