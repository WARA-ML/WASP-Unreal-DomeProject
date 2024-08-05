// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <GameFramework/PlayerController.h>
#include "CoreMinimal.h"
#include "WASPPlayerController.generated.h"

class UEnhancedInputLocalPlayerSubsystem;
class AWASPCharacter;
class AWASPHUD;
class AWASPActor;
class UWASPGameInstance;

/**
 * 
 */
UCLASS()
class WASPDOME_API AWASPPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;

	void OpenMainMenu();
	void ShowMouse();
	void HideMouse();

	// Keyboard Input
	void OnLeftMouseClicked();
	void OnLeftMouseReleased();

	void LoadWorld1();
	void LoadWorld2();
	void LoadWorld3();
	void LoadWorld4();
	void LoadWorld5();
	void SpawnAvatar();

private:
	UPROPERTY()
	const UWASPGameInstance* GameInstance = nullptr;

	UPROPERTY()
	AWASPCharacter* MainCharacter = nullptr;

	UPROPERTY()
	AWASPActor* Avatar = nullptr;

	UPROPERTY()
	AWASPHUD* HUD = nullptr;

	UPROPERTY()
	UEnhancedInputLocalPlayerSubsystem* PlayerInputSubsystem = nullptr;
};
