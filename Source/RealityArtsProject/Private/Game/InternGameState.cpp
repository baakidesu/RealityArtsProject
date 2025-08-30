// Copyright baakidesu

#include "Game/InternGameState.h"

#include "Net/UnrealNetwork.h"

void AInternGameState::Multicast_Upgrade_Implementation()
{
	OnUpgradeUnlocked.Broadcast();
}

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

void AInternGameState::OnRep_Upgrade()
{
	OnUpgradeUnlocked.Broadcast();
}


void AInternGameState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AInternGameState, DidWin);
	DOREPLIFETIME(AInternGameState, GameEnded);
}
