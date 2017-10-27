// Ben Wolfenbarger Copyright 2017

#include "TankAimingComponent.h"
#include "TankTurret1.h"
#include "BattleTank.h"
#include "TankBarrel.h"
#include "Kismet/GameplayStatics.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"

// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false; // TODO Should this tick?

	// ...
}

void UTankAimingComponent::SetBarrelReference(UTankBarrel* BarrelToSet)
{
	if (!BarrelToSet) { return;  }
	Barrel = BarrelToSet;
}

void UTankAimingComponent::SetTurretReference(UTankTurret1* TurretToSet)
{
	if (!TurretToSet) { return; }
	Turret = TurretToSet;
}

void UTankAimingComponent::AimAt(FVector HitLocation, float LaunchSpeed)
{
	if (!Barrel) { return; }

	// Calculate OutVelocity
	FVector OutLaunchVeolcity;
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));
	bool bHaveAimSolution = UGameplayStatics::SuggestProjectileVelocity
	(
		this,
		OutLaunchVeolcity,
		StartLocation,
		HitLocation,
		LaunchSpeed,
		false,
		0,
		0,
		ESuggestProjVelocityTraceOption::DoNotTrace // Comment this line to produce bug
	);

	if (bHaveAimSolution)
	{
		auto AimDirection = OutLaunchVeolcity.GetSafeNormal();
		MoveBarrelTowards(AimDirection);
	}
	// else for UE_LOG
}

void UTankAimingComponent::MoveBarrelTowards(FVector AimDirection)
{
	// Work out difference between current barrel rotation and AimDirection
	auto BarrelRotator = Barrel->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation();
	auto DeltaRotator = AimAsRotator - BarrelRotator;
	

	
	Barrel->Elevate(DeltaRotator.Pitch); // TODO remove magic number
	Turret->Rotate(DeltaRotator.Yaw);
	
}