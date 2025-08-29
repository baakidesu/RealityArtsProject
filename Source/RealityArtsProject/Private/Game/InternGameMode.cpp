// Copyright baakidesu


#include "Game/InternGameMode.h"
#include "NavigationSystem.h"
#include "Character/InternEnemy.h"
#include "Game/InternGameState.h"


AInternGameMode::AInternGameMode()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AInternGameMode::IncreaseWaveIndexAndSpawnEnemies()
{
	if (!WaveEnemyCount.IsValidIndex(CurrentWaveIndex))
	{
		//TODO:: END GAME WIN
		GetWorldTimerManager().SetTimer(TimerHandle, this, &AInternGameMode::DelayedWinGame, 3.0f, false);
		return;
	}
	
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
			AInternEnemy* SpawnedEnemy = GetWorld()->SpawnActor<AInternEnemy>(EnemyActorClass, RandomPoint.Location, FRotator::ZeroRotator);
			if (SpawnedEnemy != nullptr)
			{
				SpawnedEnemy->OnDeath.AddDynamic(this, &AInternGameMode::OnEnemyDeath);
			}
		}

		TotalEnemiesToKill++;
	}
	CurrentWaveIndex++;
}

void AInternGameMode::EndGame(bool bDidWin)
{
	if (AInternGameState* GS = GetGameState<AInternGameState>())
	{
		GS->SetHowGameEnds(bDidWin);
	}
}

void AInternGameMode::OnEnemyDeath(AInternEnemy* Enemy)
{
	if (Enemy && Enemy->HealthBarWidget)
	{
		Enemy->HealthBarWidget->DestroyComponent();
	}
	
	DiedEnemyCount++;
	if (DiedEnemyCount == TotalEnemiesToKill)
	{
		TotalEnemiesToKill = 0;
		DiedEnemyCount = 0;
		IncreaseWaveIndexAndSpawnEnemies();
	}
}

void AInternGameMode::DelayedWinGame()
{
	EndGame(true);
}
