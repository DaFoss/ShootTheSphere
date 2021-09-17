// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Gameframework/GameModeBase.h"
#include "STSGameMode.generated.h"

class ASTSSpawningHub;

UCLASS()
class SHOOTTHESPHERE_API ASTSGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ASTSGameMode();

	virtual void StartPlay() override;
	
	int32 GetWaveCount() { return WaveCount; }

	//hitted sphere decreasing count of needable spheres to new wave
	//increase kill count
	//if count of needable spheres to new wave call new spawn
	void HitTheSphere();

	int32 GetHittedSpheresCount() { return HittedSpheresCount; }

private:
	UPROPERTY(EditAnywhere)
	TSubclassOf<ASTSSpawningHub> SpawningHubClass;

	UPROPERTY(VisibleAnywhere)
	ASTSSpawningHub* SpawningHub;

	UPROPERTY(EditAnywhere, Category = "Settings", meta = (ClampMin = "1", ClampMax = "20"))
	int32 QuantityOfSpheresToStartNewWave;

	UPROPERTY(VisibleAnywhere)
	int32 WaveCount;

	UPROPERTY(VisibleAnywhere, Category = "Statistic")
	int32 HittedSpheresCount;
};
