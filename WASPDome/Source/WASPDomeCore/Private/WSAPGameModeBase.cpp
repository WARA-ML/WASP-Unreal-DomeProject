// Fill out your copyright notice in the Description page of Project Settings.


#include "WSAPGameModeBase.h"
#include "WASPPlayerController.h"

AWSAPGameModeBase::AWSAPGameModeBase()
{
	PlayerControllerClass = AWASPPlayerController::StaticClass();
}
