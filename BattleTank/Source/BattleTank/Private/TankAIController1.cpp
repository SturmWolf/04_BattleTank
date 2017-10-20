// Ben Wolfenbarger Copyright 2017

#include "TankAIController1.h"
#include "BattleTank.h"

void ATankAIController1::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControllerTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController Not Possessing Tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController Posessing %s"), *(ControlledTank->GetName()));
	}
}

ATank* ATankAIController1::GetControllerTank() const
{

	return Cast<ATank>(GetPawn());

}
