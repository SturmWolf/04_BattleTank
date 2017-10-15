// Ben Wolfenbarger Copyright 2017

#include "TankAIController.h"
#include "BattleTank.h"



void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController Not Possessing Tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController Posessing %s"), *(ControlledTank->GetName()));
	}
}

ATank* ATankAIController::GetControlledTank() const
{

	return Cast<ATank>(GetPawn());
}
