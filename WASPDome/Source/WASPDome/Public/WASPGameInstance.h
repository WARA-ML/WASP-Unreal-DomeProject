// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "LevelSequence.h"
#include "WASPGameInstance.generated.h"

class ALevelSequenceActor;

/**
 * 
 */
UCLASS()
class WASPDOME_API UWASPGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	UWASPGameInstance();

private:
	UPROPERTY()
	ULevelSequence* LevelSequence;
};
