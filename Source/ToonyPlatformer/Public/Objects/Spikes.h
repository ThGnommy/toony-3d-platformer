// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Spikes.generated.h"

UCLASS()
class TOONYPLATFORMER_API ASpikes : public AActor
{
	GENERATED_BODY()
	
public:	
	ASpikes();

protected:
	virtual void BeginPlay() override;
	
private:

	int32 damage{};
	
	UPROPERTY(EditAnywhere)
	TObjectPtr<USceneComponent> sceneComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = true)) 
	TObjectPtr<UStaticMeshComponent> staticMeshComponent;
	
	UFUNCTION()
	void OnBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};
