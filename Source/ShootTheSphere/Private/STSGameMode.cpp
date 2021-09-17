// Fill out your copyright notice in the Description page of Project Settings.


#include "STSGameMode.h"
#include "ShootTheSphere/ShootTheSphereHUD.h"
#include "ShootTheSphere/ShootTheSphereCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "STSSpawningHub.h"
#include "STSGameHUD.h"

DEFINE_LOG_CATEGORY_STATIC(LogSTSGameMode, All, All)

ASTSGameMode::ASTSGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	HUDClass = ASTSGameHUD::StaticClass();
}

void ASTSGameMode::StartPlay()
{
	Super::StartPlay();

	if (GetWorld())
	{
		if (!SpawningHubClass) return;

		QuantityOfSpheresToStartNewWave = 10;
		WaveCount = 1;
		HittedSpheresCount = 0;

		SpawningHub = GetWorld()->SpawnActor<ASTSSpawningHub>(SpawningHubClass);
	}
}

//hitted sphere decreasing count of needable spheres to new wave
//increase kill count
//if count of needable spheres to new wave call new spawn
void ASTSGameMode::HitTheSphere()
{ 
	--QuantityOfSpheresToStartNewWave;
	++HittedSpheresCount;

	if (QuantityOfSpheresToStartNewWave == 0)
	{
		UE_LOG(LogSTSGameMode, Display, TEXT("New Wave!!!"));
		++WaveCount;
		SpawningHub->SpawnSpheres();
		QuantityOfSpheresToStartNewWave = 10;
	}
}