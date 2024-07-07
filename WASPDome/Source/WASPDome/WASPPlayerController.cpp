// Fill out your copyright notice in the Description page of Project Settings.


#include "WASPDome/WASPPlayerController.h"
#include <GameFramework/PlayerStart.h>
#include <Kismet/GameplayStatics.h>
#include "WASPDome/WASPGameInstance.h"
#include "WASPDome/Public/WASPCharacter.h"
#include "WASPUserInterface/Public/WASPHUD.h"
#include "WASPUserInterface/Public/WASPUserInterfaceWidget.h"

void AWASPPlayerController::BeginPlay()
{
	Super::BeginPlay();

	GameInstance = Cast<UWASPGameInstance>(GetGameInstance());
	MainCharacter = Cast<AWASPCharacter>(GetPawn());
	check(MainCharacter)

	OnPossess(MainCharacter);

	TArray<AActor*> FoundActors{};
	UGameplayStatics::GetAllActorsOfClass(
		GetWorld(),
		APlayerStart::StaticClass(),
		FoundActors);

	const APlayerStart* PlayerStart = Cast<APlayerStart>(FoundActors[0]);

	MainCharacter->SetActorLocation(PlayerStart->GetActorLocation());
	HUD = Cast<AWASPHUD>(GetHUD());
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

	InputComponent->BindAction(
		"OpenMainMenu",
		IE_Pressed,
		this,
		&AWASPPlayerController::OpenMainMenu);
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

void AWASPPlayerController::OpenMainMenu()
{
	if (!HUD->GetUserWidgetInterface()->IsVisible())
	{
		HUD->GetUserWidgetInterface()->Open();
		ShowMouse();
		PushInputComponent(InputComponent);
	}
	else
	{
		HUD->GetUserWidgetInterface()->Close();
		HideMouse();
		PopInputComponent(InputComponent);
	}
}

void AWASPPlayerController::ShowMouse()
{
	SetShowMouseCursor(true);
	bEnableClickEvents = true;
	bEnableMouseOverEvents = true;
	bShowMouseCursor = true;
}

void AWASPPlayerController::HideMouse()
{
	SetShowMouseCursor(false);
	bEnableClickEvents = false;
	bEnableMouseOverEvents = false;
	bShowMouseCursor = false;
}

void AWASPPlayerController::OnLeftMouseClicked()
{
}

void AWASPPlayerController::OnLeftMouseReleased()
{
}
