// Fill out your copyright notice in the Description page of Project Settings.

#include "CppGameGameModeBase.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"
#include "InteractableActor.h"

void ACppGameGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	UWorld* World = GetWorld();

	Character = Cast<AFpsCharacter>(UGameplayStatics::GetPlayerPawn(World, 0));
	World->GetTimerManager().SetTimer(SpawnObstacleTimerHandle, this, &ACppGameGameModeBase::SpawnObstacles, ObstacleSpawnInterval, true);
	World->GetTimerManager().SetTimer(IncreaseSpawnSpeedTimerHandle, this, &ACppGameGameModeBase::IncreaseSpawnSpeed, 1.0f, true);
}

void ACppGameGameModeBase::SpawnObstacles()
{
	FVector LocationInFrontOfCharacter = Character->GetActorLocation() + Character->GetActorForwardVector() * ObstacleSpawnDistance.X;

	float yPositions[3] = {-ObstacleSpawnDistance.Y, 0, ObstacleSpawnDistance.Y};
	float yPosition = yPositions[FMath::RandRange(0, sizeof(yPositions) - 1)];

	FVector SpawnLocation = FVector(LocationInFrontOfCharacter.X, yPosition, ObstacleSpawnDistance.Z);

	GetWorld()->SpawnActor<AInteractableActor>(ObstacleClassToSpawn, SpawnLocation, FRotator::ZeroRotator);

	UE_LOG(LogTemp, Warning, TEXT("Obstacle spawned %s"), *SpawnLocation.ToString());
}

void ACppGameGameModeBase::IncreaseSpawnSpeed()
{
	float NewInterval = ObstacleSpawnInterval - 0.1 * ObstacleSpawnSpeedIncreaseFactor;
	ObstacleSpawnInterval = FMath::Clamp(NewInterval, 0.0f, ObstacleSpawnInterval);
}
