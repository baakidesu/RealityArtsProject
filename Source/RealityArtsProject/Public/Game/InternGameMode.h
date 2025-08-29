// Copyright baakidesu

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "InternGameMode.generated.h"

/**
 * 
 */
UCLASS()
class REALITYARTSPROJECT_API AInternGameMode : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	AInternGameMode();

protected:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Wave")
	TArray<int32> WaveEnemyCount;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Wave")
	TSubclassOf<AInternEnemy> EnemyActorClass;

	UPROPERTY(BlueprintReadOnly, Category="Wave")
	int32 CurrentWaveIndex = 0;
	
	UFUNCTION(BlueprintCallable, Category="Wave")
	void IncreaseWaveIndexAndSpawnEnemies();

	UFUNCTION(BlueprintCallable, Category="Game Condition")
	void EndGame(bool bDidWin);

private:

	UFUNCTION()   //This function calls EndGame(true).
	void DelayedWinGame();

	FTimerHandle TimerHandle;

	UFUNCTION()
	void OnEnemyDeath(AInternEnemy* Enemy);
	float DiedEnemyCount = 0;
	
	int32 TotalEnemiesToKill = 0;
};
