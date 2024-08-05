// Fill out your copyright notice in the Description page of Project Settings.


#include "WASPDome/WASPPlayerController.h"
#include <EnhancedInputSubsystems.h>
#include <GameFramework/PawnMovementComponent.h>
#include <GameFramework/PlayerStart.h>
#include <Kismet/GameplayStatics.h>

#include "WASPActor.h"
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

	PlayerInputSubsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	check(PlayerInputSubsystem);

	// PlayerInputSubsystem->AddMappingContext(MainCharacter->GetCharacterMappingContext(), 0);

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
		"3",
		IE_Pressed,
		this,
		&AWASPPlayerController::LoadWorld3);

	InputComponent->BindAction(
		"4",
		IE_Pressed,
		this,
		&AWASPPlayerController::LoadWorld4);

	InputComponent->BindAction(
		"5",
		IE_Pressed,
		this,
		&AWASPPlayerController::LoadWorld5);

	InputComponent->BindAction(
		"OpenMainMenu",
		IE_Pressed,
		this,
		&AWASPPlayerController::OpenMainMenu);

	InputComponent->BindAction(
		"SpawnAvatar",
		IE_Pressed,
		this,
		&AWASPPlayerController::SpawnAvatar);
}

void AWASPPlayerController::LoadWorld1()
{
	const FName World = "SomeLevel";

	UGameplayStatics::OpenLevel(this, World);
}

void AWASPPlayerController::LoadWorld2()
{
	const FName World = "Main";

	UGameplayStatics::OpenLevel(this, World);
}

void AWASPPlayerController::LoadWorld3()
{
	const FName World = "PolarFacility_Example_Map_Daytime";

	UGameplayStatics::OpenLevel(this, World);
}

void AWASPPlayerController::LoadWorld4()
{
	const FName World = "Demonstration";

	UGameplayStatics::OpenLevel(this, World);
}

void AWASPPlayerController::LoadWorld5()
{
	const FName World = "AdvancedVillagePack_Showcase";

	UGameplayStatics::OpenLevel(this, World);
}

void AWASPPlayerController::OpenMainMenu()
{
	if (!HUD->GetUserWidgetInterface()->IsVisible())
	{
		HUD->GetUserWidgetInterface()->Open();
		ShowMouse();
		PushInputComponent(InputComponent);
		PlayerInputSubsystem->RemoveMappingContext(MainCharacter->GetCharacterMappingContext());
	}
	else
	{
		HUD->GetUserWidgetInterface()->Close();
		HideMouse();
		PopInputComponent(InputComponent);
		PlayerInputSubsystem->AddMappingContext(MainCharacter->GetCharacterMappingContext(), 0);
	}
}

void AWASPPlayerController::SpawnAvatar()
{
	Avatar = GetWorld()->SpawnActor<AWASPActor>(
		AWASPActor::StaticClass(),
		MainCharacter->GetActorLocation() + FVector(100.f, 0.f, 0.f),
		MainCharacter->GetActorRotation() + FRotator(0.f, 180.f, 0.f));
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
