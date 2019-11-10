// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "FpsCharacter.generated.h"

UCLASS()
class CPPGAME_API AFpsCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AFpsCharacter();

	UPROPERTY(EditAnywhere, Category = "Interaction")
	float TraceRange{1000};


	UPROPERTY(EditAnywhere, Category = "Movement")
	float MovementSpeed{1};

	UFUNCTION(BlueprintCallable, Category = "Interaction")
	void Interact();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	FHitResult Trace();
	void MoveRight(float Value);
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
