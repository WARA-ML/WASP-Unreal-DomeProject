// Fill out your copyright notice in the Description page of Project Settings.


#include "WASPUserInterface/Public/WASPUserInterfaceWidget.h"
#include <Kismet/GameplayStatics.h>
#include "WASPDome/WASPPlayerController.h"
#include "WASPUIComponents/Public/Buttons/ImageButton.h"
#include "WASPUIComponents/Public/Buttons/TextButton.h"
#include "WASPUserInterface/Public/WASPHUD.h"

void UWASPUserInterfaceWidget::NativeConstruct()
{
	Super::NativeConstruct();

	const AWASPPlayerController* PlayerController = Cast<AWASPPlayerController>(
		GetOwningPlayer());

	SetVisibility(ESlateVisibility::Visible);

	WASPHUD = Cast<AWASPHUD>(PlayerController->GetHUD());
}

void UWASPUserInterfaceWidget::InitializeUserInterface()
{
	LoadMapText->OnClicked.AddDynamic(this, &UWASPUserInterfaceWidget::LoadWorldMap);
	LoadMapImage->OnClicked.AddDynamic(this, &UWASPUserInterfaceWidget::LoadWorldMap2);
}

void UWASPUserInterfaceWidget::Open()
{
	SetVisibility(ESlateVisibility::Visible);
	OnUserInterfaceOpened.Broadcast();
}

void UWASPUserInterfaceWidget::Close()
{
	SetVisibility(ESlateVisibility::Collapsed);
	OnUserInterfaceClosed.Broadcast();
}

void UWASPUserInterfaceWidget::NativeDestruct()
{
	Super::NativeDestruct();
}

void UWASPUserInterfaceWidget::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);
}

void UWASPUserInterfaceWidget::LoadWorldMap()
{
	/** TODO: LevelLoader to load level and set it up
	 * Can we control a level through code additional to blueprint?
	 * UWorld, ULevel, LevelScriptActor, LevelStreamerActor
	 *
	 * WorldPartitionCommandletHelpers::LoadWorld(LevelName);
	 **/

	// FString LevelName = FString("StarterMap");
	// FLatentActionInfo LatentInfo;
	// UGameplayStatics::LoadStreamLevel(
	// 	this,
	// 	*LevelName,
	// 	true,
	// 	true,
	// 	LatentInfo);

	const FName World2 = "Main";

	UGameplayStatics::OpenLevel(this, World2);

	// UE_LOG(LogWASPUserInterface, Error, TEXT("Clicked Text button"));
	Close();
}

void UWASPUserInterfaceWidget::LoadWorldMap2()
{
	/** TODO: LevelLoader to load level and set it up
	 * Can we control a level through code additional to blueprint?
	 * UWorld, ULevel, LevelScriptActor, LevelStreamerActor
	 *
	 * WorldPartitionCommandletHelpers::LoadWorld(LevelName);
	 **/

	// FString LevelName = FString("SecondMap");
	// FLatentActionInfo LatentInfo;
	// UGameplayStatics::LoadStreamLevel(
	// 	this,
	// 	*LevelName,
	// 	true,
	// 	true,
	// 	LatentInfo);

	const FName World1 = "SomeLevel";

	UGameplayStatics::OpenLevel(this, World1);

	// UE_LOG(LogWASPUserInterface, Error, TEXT("Clicked Image button"));
	Close();
}
