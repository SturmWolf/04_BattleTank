// Copyright Ben Wolfenbarger

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class UTankBarrel;
class AProjectile;


UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:

	UFUNCTION(BluePrintCallable, Category = "Firing")
		void Fire();


private:	// Sets default values for this pawn's properties
	ATank();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// TODO Remove once firing is moved to AimingComponent
	UPROPERTY(EditAnywhere, Category = "Firing")
		float LaunchSpeed = 10000; 

	UPROPERTY(EditAnywhere, Category = "Setup")
		TSubclassOf<AProjectile> ProjectileBlueprint; 

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float ReloadTimeInSeconds = 3;

	// Local barrel reference for spawning 
	UTankBarrel* Barrel = nullptr; // TODO REMOVE

	double LastFireTime = 0;
};
