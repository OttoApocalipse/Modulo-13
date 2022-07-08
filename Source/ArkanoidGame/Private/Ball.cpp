// Fill out your copyright notice in the Description page of Project Settings.


#include "Ball.h"

// Sets default values
ABall::ABall()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Sphere = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Sphere"));
	RootComponent = Sphere;

}


// Called every frame
void ABall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (CurrentSpeed <= 0) return;

	FVector velocity = GetVelocity();

	if (velocity.IsNearlyZero()) return;

	velocity.Normalize();
	const float Torelance = 0.1;
	if (FMath::IsNearlyZero(velocity.X, Torelance))
	{
		velocity.X = Torelance * FMath::RandBool() ? 1 : -1;
	}

	if (FMath::IsNearlyZero(velocity.Z, Torelance))
	{
		velocity.Z = Torelance * FMath::RandBool() ? 1 : -1;
	}

	velocity.Normalize();
	velocity *= CurrentSpeed;
	Sphere->SetPhysicsLinearVelocity(velocity);

}

void ABall::Launch()
{
	Sphere->AddImpulse(LaunchDirection.GetSafeNormal() * LaunchSpeed, NAME_None, true);
	CurrentSpeed = LaunchSpeed;
}

