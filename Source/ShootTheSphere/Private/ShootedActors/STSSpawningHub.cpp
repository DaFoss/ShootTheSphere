// Fill out your copyright notice in the Description page of Project Settings.


#include "STSSpawningHub.h"
#include "Engine/World.h"
#include "ShootedActors/STSBaseActor.h"

DEFINE_LOG_CATEGORY_STATIC(LogSpawningHub, All, All)

ASTSSpawningHub::ASTSSpawningHub()
{
	PrimaryActorTick.bCanEverTick = false;

	QuantityOfSpheres = 15;
	IncreasingQuantityOfSpheres = 0.1f;
	MinRadiusOfSpawning = 500.0f;
	RadiusOfSpawning = 2000.f;
	IncreaseRadiusOfSpawning = 0.05f;
	MinimalSizeOfSphere = FVector(0.3f);
	DecreasingSphereScaleStep = 0.05f;
}

void ASTSSpawningHub::BeginPlay()
{
	Super::BeginPlay();
	
	SpawnSpheres();
}

//receive random vector for new sphere
FVector ASTSSpawningHub::GetRandomPositionForNewSphere()
{
	//Generate random number in degrees for spawning spheres
	float RandomAngleInDegrees = FMath::FRandRange(0, 360.f);
	float RandomRadiusOfSpawning = FMath::FRandRange(MinRadiusOfSpawning, RadiusOfSpawning);

	float XPosition = PlayerLocation.X + (RandomRadiusOfSpawning * FMath::Cos(RandomAngleInDegrees));
	float YPosition = PlayerLocation.Y + (RandomRadiusOfSpawning * FMath::Sin(RandomAngleInDegrees));

	return FVector(XPosition, YPosition, 0.0f);
}

void ASTSSpawningHub::SpawnSpheres()
{
	if (!ShootingSphereClass) return;

	if (GetWorld())
	{
		//Get Player Location
		PlayerLocation = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation();

		//increase radius of spawning
		if (!bIsFirstStart)
		{
			RadiusOfSpawning += RadiusOfSpawning * IncreaseRadiusOfSpawning;
			QuantityOfSpheres += QuantityOfSpheres * IncreasingQuantityOfSpheres;
		}

		//Create new spheres 
		int NewSpheres = QuantityOfSpheres;
		FVector SphereScale = FVector(1.f);
		while (NewSpheres)
		{
			FVector SpawnLocation = PlayerLocation + GetRandomPositionForNewSphere();
			SpawnPosition = FTransform(FRotator::ZeroRotator, SpawnLocation);

			//spawning new sphere
			ASTSBaseActor* SpawnedSphere = GetWorld()->SpawnActor<ASTSBaseActor>(ShootingSphereClass, SpawnPosition);
			//check if it is created due to flag DontSpawnIfColliding
			if (IsValid(SpawnedSphere))
			{
				SpawnedSphere->SetActorScale3D(FVector(SphereScale));
				if (!SphereScale.Equals(MinimalSizeOfSphere))
				{
					SphereScale -= FVector(DecreasingSphereScaleStep);
				}
				--NewSpheres;
			}
		}
	}

	bIsFirstStart = false;
}