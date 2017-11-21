// Copyright Ben Wolfenbarger

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE(FTankDelegate);

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

private:

	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
		 int32 StartingHealth = 100;
	
	UPROPERTY(VisibleAnywhere, Category = "Health")
		int32 CurrentHealth; // Initialised in Begin Play();

public:


	FTankDelegate OnDeath;

	// returns current health as a percentage of starting health between 0 and 1.
	UFUNCTION(BluePrintPure, Category = "Health")
		float GetHealthPercent() const;

	// Sets default values for this pawn's properties
	ATank();

	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const & DamageEvent, class AController * EventInstigator, AActor * DamageCauser) override;


};
