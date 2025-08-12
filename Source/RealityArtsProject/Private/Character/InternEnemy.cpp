// Copyright baakidesu


#include "Character/InternEnemy.h"

#include "Game/InternGameState.h"
#include "Kismet/GameplayStatics.h"

void AInternEnemy::Die()
{
	SetLifeSpan(5.f);

	AInternGameState* GameState = Cast<AInternGameState>(UGameplayStatics::GetGameState(this));
	if (GameState && HasAuthority())
	{
		GameState->IncreaseDiedEnemyCount();
	}

	Super::Die();
}
