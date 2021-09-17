// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "STSGameDataWidget.generated.h"

class ASTSGameMode;

UCLASS()
class SHOOTTHESPHERE_API USTSGameDataWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = "UI")
	int32 GetWaveCount() const;

	UFUNCTION(BlueprintCallable, Category = "UI")
	int32 GetHittedSpheres() const;

private:
	ASTSGameMode* GetSTSGameMode()const;
};
