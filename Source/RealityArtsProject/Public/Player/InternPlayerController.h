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
	void CreateGameOverWidget(bool DidWin);

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget | End Game Properties")
	TSubclassOf<UUserWidget> LoseWidgetClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget | Game Properties")
	TSubclassOf<UUserWidget> OverlayWidgetClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget | End Game Properties")
	TSubclassOf<UUserWidget> WinWidgetClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget | Game Properties")
	TSubclassOf<UUserWidget> UpgradeWidgetClass;

	UFUNCTION(BlueprintCallable)
	void CreateUpgradeWidget();

	UPROPERTY(BlueprintReadWrite)
	UUserWidget* OverlayWidget;
	
	UPROPERTY(BlueprintReadWrite)
	UUserWidget* UpgradeWidget;

private:
	void FocusWidget(UUserWidget* WidgetToFocus, bool bPauseGame);

	void UnfocusWidget(UUserWidget* WidgetToUnfocus);

	UFUNCTION(BlueprintCallable)
	void UnfocusUpgradeWidget();
};
