// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

//General Log
DECLARE_LOG_CATEGORY_EXTERN(LogWASPGeneral, Log, All);

//Logging during game startup
DECLARE_LOG_CATEGORY_EXTERN(LogWASPMouse, Log, All);

//Logging for your AI systemW
DECLARE_LOG_CATEGORY_EXTERN(LogWASPAI, Log, All);

//Logging for a that troublesome system
DECLARE_LOG_CATEGORY_EXTERN(LogWASPGameInstance, Log, All);

//Logging for Widgets
DECLARE_LOG_CATEGORY_EXTERN(LogWASPWidget, Log, All);

//Logging for UI and HUB
DECLARE_LOG_CATEGORY_EXTERN(LogWASPUserInterface, Log, All);

//Logging for Critical Errors that must always be addressed
DECLARE_LOG_CATEGORY_EXTERN(LogWASPCriticalErrors, Log, All);
