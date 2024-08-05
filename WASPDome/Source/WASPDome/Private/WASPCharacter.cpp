// Fill out your copyright notice in the Description page of Project Settings.


#include "WASPCharacter.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "WASPDome/WASPDome.h"

AWASPCharacter::AWASPCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	SetActorEnableCollision(true);
}

UInputMappingContext* AWASPCharacter::GetCharacterMappingContext() const
{
	return CharacterMappingContext;
}

void AWASPCharacter::AddInputMappingContext()
{
	if (APlayerController* PlayerController = Cast<APlayerController>(GetController()))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<
			UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(CharacterMappingContext, 0);
		}
	}
}

void AWASPCharacter::RemoveInputMappingContext()
{
	if (APlayerController* PlayerController = Cast<APlayerController>(GetController()))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<
			UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->RemoveMappingContext(CharacterMappingContext);
		}
	}
}

void AWASPCharacter::MoveForward(const FInputActionValue& Value)
{
	float MovementValue = Value.Get<float>();
	AddMovementInput(GetActorForwardVector(), MovementValue);

	// FVector NewLocation = FVector(
	// 	GetActorLocation().X + MovementValue * 10.0f,
	// 	GetActorLocation().Y,
	// 	GetActorLocation().Z); // Adjust the multiplier as needed for the speed
	//
	// SetActorLocation(NewLocation, false);
}

void AWASPCharacter::MoveRight(const FInputActionValue& Value)
{
	float MovementValue = Value.Get<float>();
	AddMovementInput(GetActorRightVector(), MovementValue);

	// FVector NewLocation = FVector(
	// 	GetActorLocation().X,
	// 	GetActorLocation().Y + MovementValue * 10.0f,
	// 	GetActorLocation().Z); // Adjust the multiplier as needed for the speed
	//
	// SetActorLocation(NewLocation, false);
}

void AWASPCharacter::MoveUp(const FInputActionValue& Value)
{
	float MovementValue = Value.Get<float>();

	UE_LOG(LogWASPGeneral, Error, TEXT("Location: %s"), *GetActorLocation().ToString());

	FVector NewLocation = FVector(
		GetActorLocation().X,
		GetActorLocation().Y,
		GetActorLocation().Z + MovementValue * 10.0f); // Adjust the multiplier as needed for the speed

	SetActorLocation(NewLocation, false);

	if (MovementValue < 0)
	{
		UE_LOG(LogWASPGeneral, Error, TEXT("MoveUp: %f"), MovementValue);
		UE_LOG(LogWASPGeneral, Error, TEXT("MoveUp: %s"), *NewLocation.ToString());
	}
	else if (MovementValue > 0)
	{
		UE_LOG(LogWASPGeneral, Error, TEXT("MoveUp: %f"), MovementValue);
		UE_LOG(LogWASPGeneral, Error, TEXT("MoveUp: %s"), *NewLocation.ToString());
	}
}

void AWASPCharacter::Turn(const FInputActionValue& Value)
{
	float TurnValue = Value.Get<float>();
	AddControllerYawInput(TurnValue);

	// FRotator NewRotation = FRotator(
	// 	GetActorRotation().Pitch,
	// 	GetActorRotation().Yaw + TurnValue,
	// 	GetActorRotation().Roll);
	//
	// SetActorRotation(NewRotation);
	// AddMovementInput(NewRotation.Vector());
}

void AWASPCharacter::LookUp(const FInputActionValue& Value)
{
	float LookUpValue = Value.Get<float>();
	AddControllerPitchInput(LookUpValue);

	// FRotator NewRotation = GetActorRotation();
	// NewRotation.Pitch += LookUpValue;
	// SetActorRotation(NewRotation);
}

void AWASPCharacter::BeginPlay()
{
	Super::BeginPlay();

	AddInputMappingContext();
}

void AWASPCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	UEnhancedInputComponent* Input = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	Input->BindAction(Ia_MoveForward, ETriggerEvent::Triggered, this, &AWASPCharacter::MoveForward);
	Input->BindAction(Ia_MoveRight, ETriggerEvent::Triggered, this, &AWASPCharacter::MoveRight);
	Input->BindAction(Ia_MoveUp, ETriggerEvent::Triggered, this, &AWASPCharacter::MoveUp);
	Input->BindAction(Ia_Turn, ETriggerEvent::Triggered, this, &AWASPCharacter::Turn);
	Input->BindAction(Ia_LookUp, ETriggerEvent::Triggered, this, &AWASPCharacter::LookUp);
}
