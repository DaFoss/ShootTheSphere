// Fill out your copyright notice in the Description page of Project Settings.

#include "STSExplosionFXComponent.h"
#include "NiagaraFunctionLibrary.h"

USTSExplosionFXComponent::USTSExplosionFXComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

}

void USTSExplosionFXComponent::PlayExplosionFX(const AActor* ActorToExplode)
{
	UNiagaraFunctionLibrary::SpawnSystemAtLocation(
		GetWorld(), 
		ExplosionEffect, 
		ActorToExplode->GetActorLocation(), 
		ActorToExplode->GetActorRotation()
	);
}