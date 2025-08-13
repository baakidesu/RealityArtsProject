// Copyright baakidesu


#include "Game/InternGameState.h"
#include "NavigationSystem.h"



void AInternGameState::IncreaseDiedEnemyCount()
{
	DiedEnemyCount++;
	if (DiedEnemyCount == TotalEnemiesToKill)
	{
		TotalEnemiesToKill = 0;
		SpawnEnemies();
	}
}

void AInternGameState::IncreaseWaveIndexAndSpawnEnemies()
{
	SpawnEnemies();
}

void AInternGameState::SpawnEnemies()
{
	for (int i = 0; i < WaveEnemyCount[CurrentWaveIndex]; i++)
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

		TotalEnemiesToKill++;
	}
	CurrentWaveIndex++;
}
