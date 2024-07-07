// Fill out your copyright notice in the Description page of Project Settings.


#include "WASPDome/WASPGameInstance.h"
#include <Kismet/GameplayStatics.h>
#include "LevelSequenceActor.h"

UWASPGameInstance::FOnStartFinished& UWASPGameInstance::GetStartFinishedEvent()
{
	return OnStartFinishedEvent;
}

void UWASPGameInstance::OnStart()
{
	Super::OnStart();

	PrepareGameInstance();

	OnStartFinishedEvent.Broadcast();
}

void UWASPGameInstance::Shutdown()
{
	Super::Shutdown();
	OnStartFinishedEvent.RemoveAll(this);
}

void UWASPGameInstance::ShutdownAfterError()
{
	Super::ShutdownAfterError();
}

void UWASPGameInstance::PrepareGameInstance()
{
	UGameplayStatics::OpenLevel(
		GetWorld(),
		FName("/Game/Map/StarterMap"));
}
