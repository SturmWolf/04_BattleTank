// Ben Wolfenbarger Copyright 2017

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

// Enum for aiming state
UENUM()
enum class EFiringStatus : uint8 
{ Aiming, 
Locked, 
Reloading 
};

// Forward Declaration
class UTankBarrel;

class UTankTurret1;

// Hold barrels properties and elevate method
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UFUNCTION(BluePrintCallable, Category = "Setup")
		void Initialise(UTankBarrel* BarrelToSet, UTankTurret1* TurretToSet);

	void AimAt(FVector HitLocation);
		
protected:
	UPROPERTY(BlueprintReadOnly, Category = "State")
		EFiringStatus FiringStatus = EFiringStatus::Aiming;

private:
	// Sets default values for this component's properties
	UTankAimingComponent();

		UPROPERTY(EditAnywhere, Category = "Firing")
		float LaunchSpeed = 10000;

	UTankBarrel* Barrel = nullptr;
	UTankTurret1* Turret = nullptr;

	void MoveBarrelTowards(FVector AimDirection);
	
};
