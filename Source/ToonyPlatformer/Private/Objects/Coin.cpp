#include "Objects/Coin.h"
#include "Kismet/GameplayStatics.h"
#include "Characters/ToonyPlatformerCharacter.h"

ACoin::ACoin()
{
	PrimaryActorTick.bCanEverTick = true;

	sceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Scene component"));

	SetRootComponent(sceneComponent);

	staticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static mesh component"));
	staticMeshComponent->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	check(staticMeshComponent);
}

void ACoin::BeginPlay()
{
	Super::BeginPlay();

	initialPosition = GetActorLocation();
	
	staticMeshComponent->OnComponentBeginOverlap.AddDynamic(this, &ACoin::OnBeginOverlap);
}

void ACoin::Tick(const float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	Rotate(DeltaSeconds);
	MoveUpAndDown(DeltaSeconds);
}

void ACoin::Rotate(float DeltaTime)
{
	const FRotator rotationToAdd{FRotator(0, moveSpeed * DeltaTime, 0)};
	AddActorLocalRotation(rotationToAdd);
}

void ACoin::MoveUpAndDown(const float DeltaTime)
{

	auto newLocation{GetActorLocation()};
	const double currentDist{FVector::Dist(initialPosition, newLocation)};
	
	if (bMovingUp && currentDist >= maxElevationDist)
	{
		bMovingUp = false;
	}
	else if (!bMovingUp && FMath::IsNearlyZero(currentDist, 10.))
	{
		bMovingUp = true;
	}

	const float movement = (bMovingUp ? moveSpeed : -moveSpeed) * DeltaTime;
	newLocation.Z += movement;

	SetActorLocation(newLocation);
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
