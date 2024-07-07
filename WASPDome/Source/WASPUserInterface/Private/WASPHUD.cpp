// Fill out your copyright notice in the Description page of Project Settings.


#include "WASPUserInterface/Public/WASPHUD.h"
#include "WASPDome/WASPGameInstance.h"
#include "WASPDome/WASPPlayerController.h"
#include "WASPUserInterface/Public/WASPUserInterfaceWidget.h"

AWASPHUD::AWASPHUD()
{
	// UserInterfaceWidget = CreateWidget<UWASPUserInterfaceWidget>(
	// 	GetWorld(),
	// 	UserInterfaceWidgetBP,
	// 	FName("UserInterface"));
}

AWASPHUD::~AWASPHUD()
{
}

UWASPUserInterfaceWidget* AWASPHUD::GetUserWidgetInterface() const
{
	return UserInterfaceWidget;
}

void AWASPHUD::BeginPlay()
{
	Super::BeginPlay();

	UWASPGameInstance* GameInstance = Cast<UWASPGameInstance>(GetGameInstance());
	AWASPPlayerController* WASPPlayerController = Cast<AWASPPlayerController>(PlayerOwner);

	UserInterfaceWidget = CreateWidget<UWASPUserInterfaceWidget>(
		PlayerOwner, UserInterfaceWidgetBP);

	UserInterfaceWidget->InitializeUserInterface();
	UserInterfaceWidget->AddToViewport(0.f);
	UserInterfaceWidget->SetVisibility(ESlateVisibility::Collapsed);
}

void AWASPHUD::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
}
