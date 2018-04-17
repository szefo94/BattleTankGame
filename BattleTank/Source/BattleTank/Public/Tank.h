// Copyright github.com/szefo94

#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"
class UTankBarrel; //Forward declaration 
class AProjectile;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:	
	
	UFUNCTION(BlueprintCallable)
	void Fire();

private:
	// Sets default values for this pawn's properties
	ATank();
	virtual void BeginPlay() override;
	
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	TSubclassOf<AProjectile> ProjectileBlueprint;


	//TODO remove once firing is moved to aiming component
	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float LaunchSpeed = 4000.0;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float ReloadTimeInSeconds = 3.0;

	//local barrel reference for spawning projectile
	UTankBarrel* Barrel = nullptr; //TODO Remove 


	double LastFireTime = 0;
};
