// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTrack.h"
#include "Engine/World.h"

void UTankTrack::SetThrottle(float Throttle)
{
	auto Time = GetWorld()->GetTimeSeconds();
	auto Name = GetName();
	UE_LOG(LogTemp, Warning, TEXT("%s tracks throttle: %f"), *Name, Throttle)
	//TODO clamp actual throttle value so player cant over-drive
}
