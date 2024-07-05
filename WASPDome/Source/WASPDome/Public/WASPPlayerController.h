﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <GameFramework/PlayerController.h>
#include "CoreMinimal.h"
#include "WASPPlayerController.generated.h"

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

	void LoadWorld1();
	void LoadWorld2();
};
