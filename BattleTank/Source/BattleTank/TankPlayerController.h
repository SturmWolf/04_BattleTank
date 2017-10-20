// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.H"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h" // Must be last include

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	ATank* GetControllerTank() const;
	
	
	virtual void BeginPlay() override;
	
};