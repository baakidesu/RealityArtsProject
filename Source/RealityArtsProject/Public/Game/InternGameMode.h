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

	UPROPERTY(BlueprintReadWrite, Category="Combat")
	float DiedEnemyCount = 0;
	
	void IncreaseDiedEnemyCount();

protected:

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Wave")
	TArray<int32> WaveEnemyCount;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Wave")
	TSubclassOf<AInternEnemy> EnemyActorClass;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Wave")
	int32 CurrentWaveIndex = 0;
	
	UFUNCTION(BlueprintCallable, Category="Wave")
	void IncreaseWaveIndexAndSpawnEnemies();

	UFUNCTION()
	void OnEnemyDeath(AInternEnemy* Enemy);

private:
	void SpawnEnemies();
	bool IncreasedByEnemy = false;
	bool SuccessfullyIncreasedWaveByTime = false;
	int32 TotalEnemiesToKill = 0;
};
