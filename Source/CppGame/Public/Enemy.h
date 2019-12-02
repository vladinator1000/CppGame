// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InteractableActor.h"
#include "AbilitySystemInterface.h"
#include "Abilities/CppAbilitySystemComponent.h"
#include "CppAttributeSet.h"
#include "Enemy.generated.h"

/**
 * 
 */
UCLASS()
class CPPGAME_API AEnemy : public AInteractableActor, public IAbilitySystemInterface
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere)
	float MovementSpeed{100};

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	UCppAbilitySystemComponent* GetAbilitySystemComponent() const override;

private:
	FTimerHandle DestroyTimerHandle;
	void Die();

protected:
	UPROPERTY()
	UCppAbilitySystemComponent* AbilitySystemComponent;

	UPROPERTY()
	UCppAttributeSet* AttributeSet;	
};
