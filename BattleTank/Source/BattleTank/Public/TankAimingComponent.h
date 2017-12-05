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
Reloading,
OutOfAmmo
};

class UTankBarrel;
class AProjectile;
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

	UFUNCTION(BluePrintCallable, Category = "Firing")
		void Fire();

	EFiringStatus GetFiringStatus() const;
	
	UFUNCTION(BluePrintCallable, Category = "Firing")
	int32 GetRoundsLeft() const;

protected:
	UPROPERTY(BlueprintReadOnly, Category = "State")
		EFiringStatus FiringStatus = EFiringStatus::Reloading;

private:
	// Sets default values for this component's properties
	UTankAimingComponent();
	
	bool IsBarrelMoving();

	virtual void BeginPlay() override;

	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;

	void MoveBarrelTowards(FVector AimDirection); // Method

	UTankBarrel* Barrel = nullptr;
	UTankTurret1* Turret = nullptr;

	 UPROPERTY(EditAnywhere, Category = "Firing")
		 float LaunchSpeed = 200000;

	 UPROPERTY(EditDefaultsOnly, Category = "Firing")
		 float ReloadTimeInSeconds = 3;

	 UPROPERTY(EditAnywhere, Category = "Firing")
		 int32 RoundsLeft = 20;

	UPROPERTY(EditAnywhere, Category = "Setup")
		TSubclassOf<AProjectile> ProjectileBlueprint;

	FVector AimDirection;

	double LastFireTime = 0;
};
