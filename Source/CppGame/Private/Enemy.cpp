// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy.h"
// #include "Engine/World.h"

void AEnemy::BeginPlay()
{
	Super::BeginPlay();
	// GetWorld()->GetTimerManager().SetTimer(DestroyTimerHandle, this, &AEnemy::Die, 3.0f, false);

	AbilitySystemComponent = CreateDefaultSubobject<UCppAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
	AttributeSet = CreateDefaultSubobject<UCppAttributeSet>(TEXT("AttributeSet"));
}

void AEnemy::Tick(float DeltaTime)
{
	AddActorLocalOffset(FVector(-MovementSpeed * DeltaTime * 10, 0, 0), true);
}

UCppAbilitySystemComponent* AEnemy::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

void AEnemy::Die()
{
	Destroy();
}