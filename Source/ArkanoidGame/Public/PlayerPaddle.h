// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PlayerPaddle.generated.h"

UCLASS()
class ARKANOIDGAME_API APlayerPaddle : public APawn
{
	GENERATED_BODY()

public:
	
	APlayerPaddle();

protected:
	
	virtual void BeginPlay() override;

public:	
	
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float Speed;

};
