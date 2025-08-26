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
	
	
	UFUNCTION()
	void HandleEndGameWidget(bool DidWin);

};
