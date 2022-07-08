// Fill out your copyright notice in the Description page of Project Settings.


#include "BrickManager.h"
#include "Brick.h"
#include "ArkanoidPlayerState.h"

// Sets default values for this component's properties
UBrickManager::UBrickManager()
{
	
	PrimaryComponentTick.bCanEverTick = true;

	
}



void UBrickManager::BeginPlay()
{
	Super::BeginPlay();

	
	
}

void UBrickManager::SpawnBricks()
{
	for (int z = 0; z < NumRows; z++)
	{
		for (int x = 0; x < NumColumns; x++)
		{
			auto* brick = GetWorld()->SpawnActor<ABrick>(BrickClass.Get());

			if (BrickExtend.IsZero())
			{
				FVector origin;
				brick->GetActorBounds(true, origin, BrickExtend);
			}
			brick->OnBrickDestroyed.AddDynamic(this, &UBrickManager::HandleBrickDestroyed);
			brick->SetActorLocation(GetPositionFor(x, z));
		}
	}
}

FVector UBrickManager::GetPositionFor(int x, int z)
{
	FVector position = StartSpawnPosition;
	position.X += x * BrickExtend.X * 2;
	position.X += x * OffsetBetweenBricks.X;
	position.Z -= z * BrickExtend.Z * 2;
	position.Z -= z * OffsetBetweenBricks.Z;

	return position;

}

void UBrickManager::HandleBrickDestroyed(ABrick* destroyedBrick)
{
	auto* playerController = GetWorld()->GetFirstPlayerController();
	if (!IsValid(playerController)) return;
	auto* playerState = playerController->PlayerState;
	if (!IsValid(playerState)) return;
}

