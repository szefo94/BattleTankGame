// Copyright github.com/szefo94
#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"

/*
 **
 * 
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()
public:
	virtual void BeginPlay() override;
private:
		virtual void Tick(float DeltaTime) override;

	//how close will ai tank move towards player in cms
		float AcceptanceRadius = 3000.;
};
