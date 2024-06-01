// Fill out your copyright notice in the Description page of Project Settings.

#include "Objects/Spikes.h"
#include "Characters/ToonyPlatformerCharacter.h"
#include "Kismet/GameplayStatics.h"

ASpikes::ASpikes()
{
	PrimaryActorTick.bCanEverTick = false;

	sceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Scene component"));

	SetRootComponent(sceneComponent);

	staticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static mesh component"));
	staticMeshComponent->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	check(staticMeshComponent);
	
	damage = 1;
}

void ASpikes::BeginPlay()
{
	Super::BeginPlay();
	
	staticMeshComponent->OnComponentBeginOverlap.AddDynamic(this, &ASpikes::OnBeginOverlap);
}

void ASpikes::OnBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
                             int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	const TWeakObjectPtr<AToonyPlatformerCharacter> player = Cast<AToonyPlatformerCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));

	const TWeakObjectPtr<AController> instigator{GetInstigatorController()};
	
	if (OtherActor == player)
	{
		UGameplayStatics::ApplyDamage(OtherActor, damage, instigator.Get(), this, UDamageType::StaticClass());
	}
}
