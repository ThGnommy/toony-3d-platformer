// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "Enums/EPlayerState.h"
#include "ToonyPlatformerPlayerState.generated.h"

UCLASS()
class TOONYPLATFORMER_API AToonyPlatformerPlayerState : public APlayerState
{
	GENERATED_BODY()

	AToonyPlatformerPlayerState();
	
public:
	UFUNCTION(BlueprintCallable)
	EPlayerState GetCurrentPlayerState() const;
	
	void SetPlayerState(EPlayerState state);
	
private:
	EPlayerState playerState{};
};
