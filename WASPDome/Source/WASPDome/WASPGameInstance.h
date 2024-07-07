// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WASPGameInstance.generated.h"

class ALevelSequenceActor;

/**
 * 
 */
UCLASS()
class WASPDOME_API UWASPGameInstance : public UGameInstance
{
	GENERATED_BODY()

	DECLARE_MULTICAST_DELEGATE(FOnStartFinished);

public:
	FOnStartFinished& GetStartFinishedEvent();

protected:
	virtual void OnStart() override;
	virtual void Shutdown() override;
	virtual void ShutdownAfterError() override;

	UPROPERTY()
	const ALevelSequenceActor* LevelSequence;

private:
	void PrepareGameInstance();

	FOnStartFinished OnStartFinishedEvent;
};
