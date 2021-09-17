// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

//this class is designed for creating and setting our spheres in the world
//also have all parameters for setting those spheres

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "STSSpawningHub.generated.h"

class ASTSBaseActor;

UCLASS()
class SHOOTTHESPHERE_API ASTSSpawningHub : public AActor
{
	GENERATED_BODY()
	
public:	
	ASTSSpawningHub();

	void SpawnSpheres();

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY()
	FVector PlayerLocation;

	UPROPERTY()
	FTransform SpawnPosition;

	UPROPERTY(EditDefaultsOnly, Category = "Settings", meta = (ClampMin = "1", ClampMax = "20"))
	int32 QuantityOfSpheres;

	UPROPERTY(EditDefaultsOnly, Category = "Settings", meta = (ClampMin = "100", ClampMax = "500"))
	float MinRadiusOfSpawning;

	UPROPERTY(EditDefaultsOnly, Category = "Settings", meta = (ClampMin = "1000", ClampMax = "2000"))
	float RadiusOfSpawning;

	UPROPERTY(EditDefaultsOnly, Category = "Settings", meta = (ClampMin = "0.1", ClampMax = "1"))
	FVector MinimalSizeOfSphere;

	UPROPERTY(EditAnywhere, Category = "Spawn Settings", meta = (ClampMin = "0", ClampMax = "1"))
	float IncreasingQuantityOfSpheres;

	UPROPERTY(EditAnywhere, Category = "Spawn Settings", meta = (ClampMin = "0", ClampMax = "1"))
	float IncreaseRadiusOfSpawning;

	UPROPERTY(EditAnywhere, Category = "Spawn Settings", meta = (ClampMin = "0.01", ClampMax = "1"))
	float DecreasingSphereScaleStep;


	UPROPERTY(EditAnywhere)
	TSubclassOf<ASTSBaseActor> ShootingSphereClass;

	bool bIsFirstStart = true;

	//receive random vector for new sphere
	FVector GetRandomPositionForNewSphere();
};
