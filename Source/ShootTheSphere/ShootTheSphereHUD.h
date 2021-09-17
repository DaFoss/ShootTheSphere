// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once 

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "ShootTheSphereHUD.generated.h"

UCLASS()
class AShootTheSphereHUD : public AHUD
{
	GENERATED_BODY()

public:
	AShootTheSphereHUD();

	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;

private:
	/** Crosshair asset pointer */
	class UTexture2D* CrosshairTex;

};

