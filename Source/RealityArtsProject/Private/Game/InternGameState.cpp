// Copyright baakidesu


#include "Game/InternGameState.h"
#include "NavigationSystem.h"



void AInternGameState::IncreaseDiedEnemyCount()
{
	DiedEnemyCount++;
	if (DiedEnemyCount == WaveEnemyCount[CurrentWaveIndex-1])
	{
		DiedEnemyCount = 0;
		IncreaseWaveIndexAndSpawnEnemies();
	}
}

void AInternGameState::IncreaseWaveIndexAndSpawnEnemies()
{
	CurrentWaveIndex++;
	for (int i = 1; i<=WaveEnemyCount[CurrentWaveIndex-1]; i++)
	{
		FVector Origin = FVector::ZeroVector;
		float Radius = 99000.f;
		
		UNavigationSystemV1* NavSys = UNavigationSystemV1::GetCurrent(GetWorld());
		if (!NavSys) return;

		FNavLocation RandomPoint;
		bool bFound = NavSys->GetRandomReachablePointInRadius(Origin, Radius, RandomPoint);

		if (bFound)
		{
			GetWorld()->SpawnActor<AActor>(EnemyActorClass, RandomPoint.Location, FRotator::ZeroRotator);
		}
	}
}
