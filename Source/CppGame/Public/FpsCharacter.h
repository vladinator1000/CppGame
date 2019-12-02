// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "Abilities/CppAbilitySystemComponent.h"
#include "CppAttributeSet.h"
#include "FpsCharacter.generated.h"

UCLASS()
class CPPGAME_API AFpsCharacter : public ACharacter, public IAbilitySystemInterface
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

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UCppAbilitySystemComponent* GetAbilitySystemComponent() const override;

protected:
	UPROPERTY()
	UCppAbilitySystemComponent* AbilitySystemComponent;

	UPROPERTY()
	UCppAttributeSet* AttributeSet;
	
	FHitResult Trace();
	void MoveRight(const float Value);
};
