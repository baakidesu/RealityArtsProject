// Copyright baakidesu

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "InternHUD.generated.h"

/**
 * 
 */
UCLASS()
class REALITYARTSPROJECT_API AInternHUD : public AHUD
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "End Game Properties")
	TSubclassOf<UUserWidget> LoseWidgetClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "End Game Properties")
	TSubclassOf<UUserWidget> WinWidgetClass;
	
	UFUNCTION()
	void HandleEndGameWidget(bool DidWin);

};
