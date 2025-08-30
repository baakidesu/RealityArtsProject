// Copyright baakidesu

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "InternGameState.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnGameEnds, bool, bDidWin);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnUpgradeUnlocked);

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

	UPROPERTY(BlueprintAssignable)
	FOnUpgradeUnlocked OnUpgradeUnlocked;

	UFUNCTION(NetMulticast, Reliable)
	void Multicast_Upgrade();

	void SetHowGameEnds(bool bDidWin);
protected:

	UFUNCTION()
	void OnRep_GameEnds();

	UFUNCTION()
	void OnRep_Upgrade();

	UPROPERTY(Replicated)
	bool GameEnded;

	UPROPERTY(ReplicatedUsing = OnRep_GameEnds)
	bool DidWin;

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

};
