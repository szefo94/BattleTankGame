// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"




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
