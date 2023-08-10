// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Items/Item.h"
#include "HealthPickup.generated.h"

/**
 * 
 */
UCLASS()
class SLASH_API AHealthPickup : public AItem
{
	GENERATED_BODY()
public:
	virtual void Tick(float DeltaTime) override;
protected:
	virtual void BeginPlay() override;
	virtual void OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;

	UPROPERTY(EditAnywhere, Category = "Health Pickup Properties")
	float Speed = 100.f;

	FVector Direction;
	float TotalDistance;
	float CurrentDistance;
	FVector Location;
	FVector Target;

	bool Collect = false;

private:
	UPROPERTY(EditAnywhere, Category = "Health Pickup Properties")
	float HealthAmount;
public:
	FORCEINLINE float GetHealthAmount() const { return HealthAmount; }
};
