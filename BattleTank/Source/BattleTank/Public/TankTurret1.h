// Ben Wolfenbarger Copyright 2017

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTurret1.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankTurret1 : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	void Rotate(float RelativeSpeed);
	

private:
	UPROPERTY(EditAnywhere, Category = Setup)
		float MaxDegreesPerSecond = 20.0;
	
};
