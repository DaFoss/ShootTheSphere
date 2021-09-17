// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "STSBaseActor.generated.h"

class UStaticMeshComponent;
class USphereComponent;
class UMaterial;
class ASTSGameMode;
class USTSExplosionFXComponent;

UCLASS()
class SHOOTTHESPHERE_API ASTSBaseActor : public AActor
{
	GENERATED_BODY()
	
public:	

	ASTSBaseActor();

protected:
	virtual void BeginPlay() override;

	//when hit the sphere destroy it and decreasing numbers for next wave
	//assigning delegate
	UFUNCTION()
	void OnComponentHit( UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, 
		FVector NormalImpulse, const FHitResult& Hit);

	//finding gamemode to get acces to spawninghub
	ASTSGameMode* GetSTSGameMode() const;

private:
	UPROPERTY(VisibleAnywhere, Category = "Mesh")
	UStaticMeshComponent* Mesh;

	UPROPERTY(VisibleAnywhere, Category = "Collision")
	USphereComponent* SphereComponent;

	UPROPERTY(EditAnywhere, Category = "Material")
	UMaterial* Material;

	UPROPERTY(VisibleAnywhere, Category = "GameMode")
	ASTSGameMode* GameMode;

	UPROPERTY(VisibleAnywhere, Category = "VFX")
	USTSExplosionFXComponent* ExplosionFXComponent;
};
