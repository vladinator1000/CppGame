// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "InteractableActor.h"
#include "FpsCharacter.h"
#include "CppGameGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class CPPGAME_API ACppGameGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

private:
	FTimerHandle SpawnObstacleTimerHandle;
	AFpsCharacter* Character;

public:
	UPROPERTY(EditAnywhere, Category = "Obstacles")
	float ObstacleSpawnInterval{1};

	UPROPERTY(EditAnywhere, Category = "Obstacles")
	float ObstacleSpawnDistance{500};

	UPROPERTY(EditAnywhere, Category = "Obstacles")
	FVector ObstacleSpawnLocation;

	UPROPERTY(EditAnywhere, Category = "Obstacles")
	TSubclassOf<AInteractableActor> ObstacleClassToSpawn;
	
	virtual void BeginPlay() override;

	void SpawnObstacles();
};
