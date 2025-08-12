// Copyright baakidesu

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "InternGameState.generated.h"

/**
 * 
 */
UCLASS()
class REALITYARTSPROJECT_API AInternGameState : public AGameStateBase
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
	TSubclassOf<AActor> EnemyActorClass;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Wave")
	int32 CurrentWaveIndex = 1;
	
	UFUNCTION(BlueprintCallable, Category="Wave")
	void IncreaseWaveIndexAndSpawnEnemies();
};
