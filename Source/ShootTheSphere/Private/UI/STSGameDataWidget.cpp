// Fill out your copyright notice in the Description page of Project Settings.


#include "STSGameDataWidget.h"
#include "STSGameMode.h"

int32 USTSGameDataWidget::GetWaveCount() const
{
	const auto GameMode = GetSTSGameMode();

	return GameMode ? GameMode->GetWaveCount() : 0;
}

int32 USTSGameDataWidget::GetHittedSpheres() const
{
	const auto GameMode = GetSTSGameMode();

	return GameMode ? GameMode->GetHittedSpheresCount() : 0;
}

ASTSGameMode* USTSGameDataWidget::GetSTSGameMode()const
{
	return GetWorld() ? Cast<ASTSGameMode>(GetWorld()->GetAuthGameMode()) : nullptr;
}