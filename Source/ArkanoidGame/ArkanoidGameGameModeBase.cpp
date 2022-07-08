// Copyright Epic Games, Inc. All Rights Reserved.


#include "ArkanoidGameGameModeBase.h"
#include "BrickManager.h"


AArkanoidGameGameModeBase::AArkanoidGameGameModeBase() : Super()
{
	BrickManager = CreateDefaultSubobject<UBrickManager>(TEXT("BrickManager"));
}

void AArkanoidGameGameModeBase::BeginPlay()
{
	Super::BeginPlay();

	BrickManager->SpawnBricks();

}

