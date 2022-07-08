// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "ArkanoidPlayerController.generated.h"


class ABall;

/**
 * 
 */
UCLASS()
class ARKANOIDGAME_API AArkanoidPlayerController : public APlayerController
{
	GENERATED_BODY()
	

public:

	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, category = "Ball")
		TSubclassOf<ABall> BallClass;

	ABall* SpawnBall();

	void StartInitialState();

	void HandleLaunch();

	void SetupInputComponent();

	UPROPERTY(EditDefaultsOnly, category = "Input")
	FName HorizontalInputAxis = TEXT("Horizontal");

	UPROPERTY(EditDefaultsOnly, category = "Input")
	FName LaunchInput = TEXT("Launch");

	UFUNCTION()
	void HandleHorizontalAxis(float Value);

	UPROPERTY(EditAnywhere, category = "Ball")
	FVector OffSetPawnInitialBall = FVector(0, 0, 20);

protected:

	virtual void BeginPlay() override;



private:


	UPROPERTY()
	ABall* HoldingBall;
};
