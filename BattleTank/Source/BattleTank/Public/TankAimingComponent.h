// Ben Wolfenbarger Copyright 2017

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

// Forward Decleration
class UTankBarrel;

class UTankTurret1;

// Hold barrels properties and elevate method
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();
	
	void SetBarrelReference(UTankBarrel* BarrelToSet);

	void SetTurretReference(UTankTurret1* TurretToSet);

	void AimAt(FVector HitLocation, float LaunchSpeed);
		

private:
	UTankBarrel* Barrel = nullptr;
	UTankTurret1* Turret = nullptr;

	void MoveBarrelTowards(FVector AimDirection);
	
};
