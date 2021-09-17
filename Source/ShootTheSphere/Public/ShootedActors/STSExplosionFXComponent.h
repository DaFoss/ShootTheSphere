// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "STSExplosionFXComponent.generated.h"

class UNiagaraSystem;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SHOOTTHESPHERE_API USTSExplosionFXComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	USTSExplosionFXComponent();

	void PlayExplosionFX(const AActor* ActorToExplode);

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "VFX")
	UNiagaraSystem* ExplosionEffect;
};
