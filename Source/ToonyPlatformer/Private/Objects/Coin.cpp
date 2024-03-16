#include "Objects/Coin.h"
#include "Kismet/GameplayStatics.h"
#include "Characters/ToonyPlatformerCharacter.h"

// Sets default values
ACoin::ACoin()
{
	PrimaryActorTick.bCanEverTick = false;

	sceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Scene component"));

	SetRootComponent(sceneComponent);

	staticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static mesh component"));
	staticMeshComponent->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
}

// Called when the game starts or when spawned
void ACoin::BeginPlay()
{
	Super::BeginPlay();
	staticMeshComponent->OnComponentBeginOverlap.AddDynamic(this, &ACoin::OnBeginOverlap);
}

void ACoin::OnBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	const TWeakObjectPtr<AToonyPlatformerCharacter> player = Cast<AToonyPlatformerCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	
	if(OtherActor == player)
	{
		// TODO: add sound and particles
		Destroy();
	}
}