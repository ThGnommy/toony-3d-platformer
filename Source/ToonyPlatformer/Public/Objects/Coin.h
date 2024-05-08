// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Coin.generated.h"

UCLASS()
class TOONYPLATFORMER_API ACoin : public AActor
{
	GENERATED_BODY()
	
public:	
	ACoin();

protected:
	virtual void BeginPlay() override;
	virtual void Tick( float DeltaSeconds );
private:

	UPROPERTY()
	FVector initialPosition = FVector::ZeroVector;
	
	UPROPERTY(EditDefaultsOnly, Category = "Movement")
	float moveSpeed{100.};

	UPROPERTY(EditDefaultsOnly, Category = "Movement")
	float maxElevationDist{100.};

	bool bMovingUp{true};
	
	UPROPERTY(EditAnywhere)
	TObjectPtr<USceneComponent> sceneComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = true)) 
	TObjectPtr<UStaticMeshComponent> staticMeshComponent;

	void Rotate(float DeltaTime);
	void MoveUpAndDown(float DeltaTime);
	
	UFUNCTION()
	void OnBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};
