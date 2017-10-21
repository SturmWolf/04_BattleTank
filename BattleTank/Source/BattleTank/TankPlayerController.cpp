// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "BattleTank.h"


	// AimTowardsCrosshair();
void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
}

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController Not Possessing Tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController Posessing %s"), *(ControlledTank->GetName()));
	}
}

ATank* ATankPlayerController::GetControlledTank() const 
{

	return Cast<ATank>(GetPawn());

}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; }

	FVector HitLocation; // OUT Parameter
	if (GetSightRayHitLocation(HitLocation)) // Has "Side Effect", is going to line trace
	{
		//UE_LOG(LogTemp, Warning, TEXT("Look Direction: %s"), *HitLocation.ToString());
		// Get World location if linetrace through crosshair

		// if it hits the landscape

			// tell controlled tank to aim at this point
	}
}

// Get World location if linetrace through crosshair
bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const
{
	// Find the crosshair position in pixel coordinates
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	auto ScreenLocation = FVector2D(ViewportSizeX * CrossHairXLocation, ViewportSizeY * CrossHairYLocation);

	// DE project the screen position of the crosshair to a world direction
	// Line Trace along that look direction, and see what we hit up to a max range
	return true;
}

