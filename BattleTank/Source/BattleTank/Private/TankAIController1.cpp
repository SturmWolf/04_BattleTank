// Ben Wolfenbarger Copyright 2017

#include "TankAIController1.h"
#include "BattleTank.h"
#include "TankAimingComponent.h"

// Depends on movement component via nav pathfinding system

void ATankAIController1::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ATankAIController1::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerTank = (GetWorld()->GetFirstPlayerController()->GetPawn());
	auto ControlledTank = (GetPawn());
	if (!PlayerTank && !ControlledTank) { return; }
	{
		// Move towards the player
		MoveToActor(PlayerTank, AcceptanceRadius); // TODO check radius is in cm

		// Aim at towards the player
		auto AimingComponent = ControlledTank->FindComponentByClass<UTankAimingComponent>();
		AimingComponent->AimAt(PlayerTank->GetActorLocation());

		AimingComponent->Fire();
		
	}

}

