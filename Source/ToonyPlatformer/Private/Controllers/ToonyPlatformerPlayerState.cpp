// Fill out your copyright notice in the Description page of Project Settings.


#include "Controllers/ToonyPlatformerPlayerState.h"

AToonyPlatformerPlayerState::AToonyPlatformerPlayerState()
{
	playerState = EPlayerState::Alive;
}

EPlayerState AToonyPlatformerPlayerState::GetCurrentPlayerState() const
{
	return playerState;
}

void AToonyPlatformerPlayerState::SetPlayerState(const EPlayerState state)
{
	playerState = state;
}
