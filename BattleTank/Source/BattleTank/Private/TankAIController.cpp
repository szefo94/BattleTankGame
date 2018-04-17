// Copyright github.com/szefo94
#include "TankAIController.h"
#include "Tank.h"
#include "Engine/World.h"
//Depends on movement component via pathfinding system

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

}


void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	auto ControlledTank = Cast<ATank>(GetPawn());
	if (PlayerTank)
	{
		//move towards player
		MoveToActor(PlayerTank,AcceptanceRadius);

		//aim towards player
		ControlledTank->AimAt(PlayerTank->GetActorLocation());

		ControlledTank->Fire(); //todo limit firing rate
	}
}

