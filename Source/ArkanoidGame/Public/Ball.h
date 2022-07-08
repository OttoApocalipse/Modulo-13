// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Ball.generated.h"

UCLASS()
class ARKANOIDGAME_API ABall : public AActor
{
	GENERATED_BODY()
	
public:	
	
	ABall();
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class UStaticMeshComponent* Sphere;

	UFUNCTION()
	void Launch();

	UPROPERTY(EditAnywhere)
	FVector LaunchDirection = FVector(1, 0, 1);

	UPROPERTY(EditAnywhere)
	float LaunchSpeed = 650;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	float CurrentSpeed;

};
