// Ben Wolfenbarger Copyright 2017

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

// Forward Decleration
class UTankBarrel;

// Hold barrels properties and elevate method
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();
	
	void SetBarrelReference(UTankBarrel* BarrelToSet);

	void AimAt(FVector HitLocation, float LaunchSpeed);
		
	// TODO add SetTurretReference

private:
	UTankBarrel* Barrel = nullptr;

	void MoveBarrelTowards(FVector AimDirection);
	
};