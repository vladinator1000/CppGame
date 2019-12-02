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

public:
	UPROPERTY(EditAnywhere, Category = "Obstacles")
	float ObstacleSpawnInterval{1.0f};

	UPROPERTY(EditAnywhere, Category = "Obstacles")
	float ObstacleSpawnSpeedIncreaseFactor{2.0f};

	UPROPERTY(EditAnywhere, Category = "Obstacles")
	FVector ObstacleSpawnDistance{500.0f, 100.0f, 50.0f};

	UPROPERTY(EditAnywhere, Category = "Obstacles")
	TSubclassOf<AInteractableActor> ObstacleClassToSpawn;
	
	virtual void BeginPlay() override;

	void SpawnObstacles();

private:
	FTimerHandle SpawnObstacleTimerHandle;
	FTimerHandle IncreaseSpawnSpeedTimerHandle;
	AFpsCharacter* Character;
	void IncreaseSpawnSpeed();
};
