// Ben Wolfenbarger Copyright 2017

#include "TankAIController1.h"
#include "BattleTank.h"
#include "Tank.h"

void ATankAIController1::BeginPlay()
{
	Super::BeginPlay();

	auto PlayerTank = GetPlayerTank();
	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController can't find player tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController found Player %s"), *(PlayerTank->GetName()));
	}
}

// Called every frame
void ATankAIController1::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (GetPlayerTank())
	{
		// Move towards the player

		// Aim at towards the player
		GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());

		// Fire if ready
	}

}

ATank* ATankAIController1::GetControlledTank() const
{

	return Cast<ATank>(GetPawn());

}

ATank* ATankAIController1::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn) { return nullptr; }
	return Cast<ATank>(PlayerPawn);
}