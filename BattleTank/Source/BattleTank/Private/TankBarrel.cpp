// Ben Wolfenbarger Copyright 2017

#include "TankBarrel.h"


void UTankBarrel::Elevate(float RelativeSpeed)
{
	// Move the barrel the right amount this frame
	// Given a max elevation speed
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, +1);
	auto ElevationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewElevation = RelativeRotation.Pitch + ElevationChange;
	auto Elevation = FMath::Clamp<float>(RawNewElevation, MinElevationDegreesPerSecond, MaxElevationDegreesPerSecond);

	SetRelativeRotation(FRotator(Elevation, 0, 0));
}
