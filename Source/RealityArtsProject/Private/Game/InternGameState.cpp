// Copyright baakidesu

#include "Game/InternGameState.h"

#include "Net/UnrealNetwork.h"

void AInternGameState::SetHowGameEnds(bool bDidWin)
{
	if (!HasAuthority()) return;

	DidWin = bDidWin;
	GameEnded = true;

	OnGameEnds.Broadcast(DidWin);
}

void AInternGameState::OnRep_GameEnds()
{
	OnGameEnds.Broadcast(DidWin);
}


void AInternGameState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AInternGameState, DidWin);
	DOREPLIFETIME(AInternGameState, GameEnded);
}
