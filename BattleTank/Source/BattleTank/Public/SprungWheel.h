// Copyright @github.com/szefo94

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SprungWheel.generated.h"
class UStaticMeshComponent;
class UPhysicsConstraintComponent;

UCLASS()
class BATTLETANK_API ASprungWheel : public AActor
{
GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASprungWheel();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	// Components
	UPROPERTY(VisibleAnywhere, Category = "Components")
	UStaticMeshComponent * Mass = nullptr;
	UPROPERTY(VisibleAnywhere, Category = "Components")
	UStaticMeshComponent * Wheel = nullptr;
	UPROPERTY(VisibleAnywhere, Category = "Components")
	UPhysicsConstraintComponent * MassWheelConstraint = nullptr;
		
};
