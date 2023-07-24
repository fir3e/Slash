// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Items/Item.h"
#include "EnergyItem.generated.h"

/**
 * 
 */
UCLASS()
class SLASH_API AEnergyItem : public AItem
{
	GENERATED_BODY()

protected:
	virtual void OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;
private:
	UPROPERTY(EditAnywhere, Category = "Energy Properties")
	float Energy;
public:
	FORCEINLINE float GetEnergy() const { return Energy; }
};
