// Fill out your copyright notice in the Description page of Project Settings.


#include "Brick.h"

ABrick::ABrick()
{
 		PrimaryActorTick.bCanEverTick = true;

}


void ABrick::NotifyHit(UPrimitiveComponent* MyComp, AActor* Other, UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit)
{
	Super::NotifyHit(MyComp, Other, OtherComp, bSelfMoved, HitLocation, HitNormal, NormalImpulse, Hit);

	OnBrickDestroyed.Broadcast(this);
	DestroyFeedback();

	if (TimeForFeedbackDestroy > 0)
	{
		SetLifeSpan(TimeForFeedbackDestroy);
	}
	else
	{
		Destroy();
	}
}

void ABrick::BeginPlay()
{
	Super::BeginPlay();
	
}



int ABrick::GetScoreValue() const
{
	return 10;
}

