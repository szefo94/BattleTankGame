// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Tank.h"



void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	auto PlayerTank = GetControlledTank();
	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController Cant find player tank"))
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController found player:  %s"), *(PlayerTank->GetName()));
	}
	///UE_LOG(LogTemp,Warning,TEXT ("PlayerControllerBeginPlay"))
}
ATank * ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());

}

ATank* ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn)
	{
		return nullptr;
	}
	return Cast<ATank>(PlayerPawn);
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if(GetPlayerTank())
	{
		//TODO move towards player

		//aim towards player
		GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());

		//todo fire if ready
	}
}