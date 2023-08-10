// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/HealthPickup.h"
#include "Interfaces/PickupInterface.h"
#include "NiagaraFunctionLibrary.h"

void AHealthPickup::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (CurrentDistance < TotalDistance && Collect)
	{
		Target = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation();
		Location = GetActorLocation();

		Direction = Target - Location;
		TotalDistance = Direction.Size();

		Direction = Direction.GetSafeNormal();


		Location += Direction * Speed * DeltaTime;

		SetActorLocation(Location);

		CurrentDistance = (Target - Location).Size();
	}
}

void AHealthPickup::BeginPlay()
{
	Super::BeginPlay();

	CurrentDistance = 0.f;
	TotalDistance = 100.f;
}

void AHealthPickup::OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	IPickupInterface* PickupInterface = Cast<IPickupInterface>(OtherActor);
	if (PickupInterface)
	{
		Collect = true;

		PickupInterface->AddHealth(this);

		//SpawnPickupSystem();
		//SpawnPickupSound();

		//Destroy();
	}
}
