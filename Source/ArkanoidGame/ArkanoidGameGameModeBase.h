// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "ArkanoidGameGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class ARKANOIDGAME_API AArkanoidGameGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	

protected:

	AArkanoidGameGameModeBase();

	virtual void BeginPlay() override;


	UPROPERTY(VisibleAnywhere)
	class UBrickManager* BrickManager;
};
