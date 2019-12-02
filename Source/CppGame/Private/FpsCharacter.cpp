// Fill out your copyright notice in the Description page of Project Settings.


#include "FpsCharacter.h"
#include "Engine/World.h"
#include "InteractableActor.h"
#include "DrawDebugHelpers.h"
#include "Engine/EngineTypes.h"
#include "Components/InputComponent.h"
#include "Components/PrimitiveComponent.h"

// Sets default values
AFpsCharacter::AFpsCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	AbilitySystemComponent = CreateDefaultSubobject<UCppAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
	AttributeSet = CreateDefaultSubobject<UCppAttributeSet>(TEXT("AttributeSet"));
	
}

// Called when the game starts or when spawned
void AFpsCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFpsCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AFpsCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AFpsCharacter::Jump);
	PlayerInputComponent->BindAction("Interact", IE_Pressed, this, &AFpsCharacter::Interact);
	PlayerInputComponent->BindAxis("MoveRight", this, &AFpsCharacter::MoveRight);
}

UCppAbilitySystemComponent* AFpsCharacter::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}


FHitResult AFpsCharacter::Trace()
{
	auto TraceStart = GetActorLocation();
	auto TraceEnd = GetActorForwardVector() * TraceRange;
	auto World = GetWorld();
	

	FCollisionQueryParams TraceParams(SCENE_QUERY_STAT(instantShot), false, Instigator);
	FHitResult OutHit;
	
	DrawDebugLine(World, TraceStart, TraceEnd, FColor::Blue, false, 1.0f);
	if (World->LineTraceSingleByChannel(OutHit, TraceStart, TraceEnd, ECC_Visibility, TraceParams))
	{
		UPrimitiveComponent* Component = OutHit.Component.Get();
		
		DrawDebugString
		(
			World,
			OutHit.Location,
			FString::Printf(TEXT("Hit component: %s"), *Component->GetName()),
			OutHit.Actor.Get(),
			FColor::Blue,
			0.3f
		);

		return OutHit;
	}

	return FHitResult(ForceInit);
}

void AFpsCharacter::Interact()
{
	FHitResult Hit = Trace();
	AInteractableActor* HitActor = Cast<AInteractableActor>(Hit.Actor);
		
	if (HitActor)
	{
		HitActor->Interact();
	}
}

void AFpsCharacter::MoveRight(const float Value)
{
	if (Value)
	{
		AddMovementInput(GetActorRightVector(), Value * GetWorld()->GetTimeSeconds() * MovementSpeed);
	}
}
