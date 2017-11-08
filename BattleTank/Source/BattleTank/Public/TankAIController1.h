// Ben Wolfenbarger Copyright 2017

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController1.generated.h"

UCLASS()
class BATTLETANK_API ATankAIController1 : public AAIController
{
	GENERATED_BODY()
	
protected:
	// How close AI tank can get to player
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
		float AcceptanceRadius = 10000;
		
private:
	virtual void BeginPlay() override;

	virtual void Tick(float Deltatime) override;


};
