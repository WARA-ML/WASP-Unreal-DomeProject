// Fill out your copyright notice in the Description page of Project Settings.


#include "WASPDome/Public/WASPPlayerController.h"

#include <Kismet/GameplayStatics.h>

void AWASPPlayerController::BeginPlay()
{
	Super::BeginPlay();
}

void AWASPPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAction(
		"1",
		IE_Pressed,
		this,
		&AWASPPlayerController::LoadWorld1);

	InputComponent->BindAction(
		"2",
		IE_Pressed,
		this,
		&AWASPPlayerController::LoadWorld2);
}

void AWASPPlayerController::LoadWorld1()
{
	const FName World1 = "SomeLevel";

	UGameplayStatics::OpenLevel(this, World1);
}

void AWASPPlayerController::LoadWorld2()
{
	const FName World2 = "Main";

	UGameplayStatics::OpenLevel(this, World2);
}
