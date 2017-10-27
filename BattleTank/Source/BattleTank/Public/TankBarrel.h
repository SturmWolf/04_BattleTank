// Ben Wolfenbarger Copyright 2017

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent)) //, hidecategories = ("Collision")) used to hide editor properties in UE4 
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	// -1 is max downward movement and +1 is max up movement
	void Elevate(float RelativeSpeed);
	
	
private:
	UPROPERTY(EditAnywhere, Category = Setup)
		float MaxDegreesPerSecond = 5;

	UPROPERTY(EditAnywhere, Category = Setup)
		float MaxElevationDegreesPerSecond = 20.0;

	UPROPERTY(EditAnywhere, Category = Setup)
		float MinElevationDegreesPerSecond = 0; 
};
