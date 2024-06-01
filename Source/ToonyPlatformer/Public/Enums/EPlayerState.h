#pragma once

#include "EPlayerState.generated.h"

UENUM(BlueprintType)
enum class EPlayerState : uint8
{
	Alive,
	Dead,
};