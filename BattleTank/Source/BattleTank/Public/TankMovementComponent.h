// Ben Wolfenbarger Copyright 2017

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/NavMovementComponent.h"
#include "TankMovementComponent.generated.h"


class UTankTrack;

/**
 * Responsible for driving the tank tracks
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankMovementComponent : public UNavMovementComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BluePrintCallable, Category = Input)
		void Initialise(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet);

	UFUNCTION(BluePrintCallable, Category = Input)
		void IntendMoveForward(float Throw);

	UFUNCTION(BluePrintCallable, Category = Input)
		void IntendTurnRight(float Throw);

	UFUNCTION(BluePrintCallable, Category = Input)
		void IntendTurnLeft(float Throw);

	
private:
	UTankTrack* LeftTrack = nullptr;
	UTankTrack* RightTrack = nullptr;
	
};
