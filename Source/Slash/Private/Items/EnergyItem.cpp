// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/EnergyItem.h"
#include "Interfaces/PickupInterface.h"
#include "NiagaraFunctionLibrary.h"

void AEnergyItem::OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	IPickupInterface* PickupInterface = Cast<IPickupInterface>(OtherActor);
	if (PickupInterface)
	{
		PickupInterface->AddEnergy(this);

		SpawnPickupSystem();
		SpawnPickupSound();

		Destroy();
	}
}
