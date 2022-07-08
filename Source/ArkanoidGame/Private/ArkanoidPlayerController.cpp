// Fill out your copyright notice in the Description page of Project Settings.


#include "ArkanoidPlayerController.h"
#include "Ball.h"


void AArkanoidPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAxis(HorizontalInputAxis, this, &AArkanoidPlayerController::HandleHorizontalAxis);
	InputComponent->BindAction(LaunchInput, IE_Pressed, this, &AArkanoidPlayerController::HandleLaunch);

}


void AArkanoidPlayerController::BeginPlay()
{
	Super::BeginPlay();

	StartInitialState();

}

void AArkanoidPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


}

void AArkanoidPlayerController::HandleHorizontalAxis(float Value)
{
	if (!IsValid(GetPawn())) return;
	GetPawn()->AddMovementInput(FVector::ForwardVector, Value);

	if (IsValid(HoldingBall))
	{
		HoldingBall->SetActorLocation(GetPawn()->GetActorLocation() + OffSetPawnInitialBall);
	}
}

ABall* AArkanoidPlayerController::SpawnBall()
{
	auto* ball = GetWorld()->SpawnActor<ABall>(BallClass.Get());

	return ball;
}

void AArkanoidPlayerController::StartInitialState()
{
	HoldingBall = SpawnBall();
	if (IsValid(HoldingBall) && IsValid(GetPawn()))
	{
		HoldingBall->SetActorLocation(GetPawn()->GetActorLocation() + OffSetPawnInitialBall);
	}
}

void AArkanoidPlayerController::HandleLaunch()
{
	if (IsValid(HoldingBall))
	{
		HoldingBall->Launch();
		HoldingBall = nullptr;
	}
}