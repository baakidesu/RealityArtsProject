// Copyright baakidesu

#pragma once

#include "CoreMinimal.h"
#include "Character/InternEnemy.h"
#include "GameFramework/GameStateBase.h"
#include "InternGameState.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnGameEnds, bool, bDidWin);

/**
 * 
 */
UCLASS()
class REALITYARTSPROJECT_API AInternGameState : public AGameStateBase
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable, Category="GameState")
	FOnGameEnds OnGameEnds;

	void SetHowGameEnds(bool bDidWin);
protected:

	UFUNCTION()
	void OnRep_GameEnds();

	UPROPERTY(Replicated)
	bool GameEnded;

	UPROPERTY(ReplicatedUsing = OnRep_GameEnds)
	bool DidWin;

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

};
