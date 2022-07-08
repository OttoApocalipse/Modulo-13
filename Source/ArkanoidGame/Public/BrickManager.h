// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "BrickManager.generated.h"


class ABrick;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ARKANOIDGAME_API UBrickManager : public UActorComponent
{
	GENERATED_BODY()

protected:
	
	virtual void BeginPlay() override;

public:	
	
	UBrickManager();

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<ABrick> BrickClass;

	UFUNCTION()
	virtual void SpawnBricks();

	UPROPERTY(EditDefaultsOnly)
	int NumRows = 4;

	UPROPERTY(EditDefaultsOnly)
	int NumColumns = 9;

	FVector BrickExtend;

	UPROPERTY(EditAnywhere)
	FVector OffsetBetweenBricks;

	FVector GetPositionFor(int x, int z);

	UPROPERTY(EditAnywhere)
	FVector StartSpawnPosition;

	UFUNCTION()
	void HandleBrickDestroyed(ABrick* destroyedBrick);




		
};
