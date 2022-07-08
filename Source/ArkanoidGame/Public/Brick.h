// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Brick.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnBrickDestroyed, class ABrick*, brick);

UCLASS()
class ARKANOIDGAME_API ABrick : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABrick();


	virtual void NotifyHit(class UPrimitiveComponent* MyComp, AActor* Other, class UPrimitiveComponent* OtherComp,
		bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit) override;


	UFUNCTION(BlueprintImplementableEvent)
	void DestroyFeedback();

	float TimeForFeedbackDestroy = 0.1;

	int GetScoreValue() const;

	UPROPERTY(BlueprintAssignable)
	FOnBrickDestroyed OnBrickDestroyed;




protected:
	
	virtual void BeginPlay() override;



};
