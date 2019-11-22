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
}

void ACppGameGameModeBase::SpawnObstacles()
{
	FVector CharacterLocation = Character->GetActorLocation();
	FVector SpawnLocation = CharacterLocation + Character->GetActorForwardVector() * ObstacleSpawnDistance;

	GetWorld()->SpawnActor<AInteractableActor>(ObstacleClassToSpawn, SpawnLocation, FRotator::ZeroRotator);

	UE_LOG(LogTemp, Warning, TEXT("Obstacle spawned %s"), *SpawnLocation.ToString());
}
