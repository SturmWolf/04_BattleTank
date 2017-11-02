// Ben Wolfenbarger Copyright 2017

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BluePrintCallable, Category = "Input")
		void SetThrottle(float Throttle);

	// Max force per track in newwtons
	UPROPERTY(EditDefaultsOnly)
		float TrackMaxDrivingForce = 28000000; // Asusume 40 ton tank, and ig acceleration
	
};
