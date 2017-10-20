// Ben Wolfenbarger Copyright 2017

#pragma once

#include "Tank.h"
#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController1.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAIController1 : public AAIController
{
	GENERATED_BODY()
	
private:
	virtual void BeginPlay() override;
	
	ATank* GetControllerTank() const;

	ATank* GetPlayerTank() const;
};
