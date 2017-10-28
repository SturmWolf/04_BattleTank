// Ben Wolfenbarger Copyright 2017

#include "TankTrack.h"
#include "BattleTank.h"

void UTankTrack::SetThrottle(float Throttle)
{
	auto Name = GetName();
	UE_LOG(LogTemp, Warning, TEXT("%s Throttle: %f"), *Name, Throttle);
}


