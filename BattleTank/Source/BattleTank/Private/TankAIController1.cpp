// Ben Wolfenbarger Copyright 2017

#include "TankAIController1.h"
#include "BattleTank.h"
#include "Tank.h"
#include "TankAimingComponent.h"

// Depends on movement component via nav pathfinding system

void ATankAIController1::BeginPlay()
{
	Super::BeginPlay();

}

void ATankAIController1::SetPawn(APawn* InPawn)
{
	Super::SetPawn(InPawn);
	if (InPawn)
	{
		auto AITank = Cast<ATank>(InPawn);
		if (!ensure(AITank)) { return; }

		// Subscribe our local method to the tanks death event
		AITank->OnDeath.AddUniqueDynamic(this, &ATankAIController1::OnAITankDeath);
	}
}

void ATankAIController1::OnAITankDeath()
{
	if (!ensure(GetPawn())) { return; } //TODO remove if ok
	GetPawn()->DetachFromControllerPendingDestroy();
}
	

// Called every frame
void ATankAIController1::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerTank = (GetWorld()->GetFirstPlayerController()->GetPawn());
	auto ControlledTank = (GetPawn());
	if (!ensure(PlayerTank && ControlledTank)) { return; }
	{
		// Move towards the player
		MoveToActor(PlayerTank, AcceptanceRadius); // TODO check radius is in cm

		// Aim at towards the player
		auto AimingComponent = ControlledTank->FindComponentByClass<UTankAimingComponent>();
		AimingComponent->AimAt(PlayerTank->GetActorLocation());

		if (AimingComponent->GetFiringStatus() == EFiringStatus::Locked)
		AimingComponent->Fire();
		
	}

}

