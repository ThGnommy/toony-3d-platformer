// Copyright Epic Games, Inc. All Rights Reserved.

#include "Controllers/ToonyPlatformerGameMode.h"
#include "Characters/ToonyPlatformerCharacter.h"
#include "UObject/ConstructorHelpers.h"

AToonyPlatformerGameMode::AToonyPlatformerGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
