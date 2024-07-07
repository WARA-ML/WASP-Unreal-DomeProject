// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WASPUserInterface/Public/WASPUserWidget.h"
#include "WASPUserInterfaceWidget.generated.h"

class AWASPHUD;
class UTextButton;
class UImageButton;

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnUserInterfaceOpened);

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnUserInterfaceClosed);

/**
 * 
 */
UCLASS()
class WASPUSERINTERFACE_API UWASPUserInterfaceWidget : public UWASPUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void InitializeUserInterface();

	UFUNCTION()
	void Open();

	UFUNCTION()
	void Close();

	UPROPERTY()
	FOnUserInterfaceOpened OnUserInterfaceOpened;

	UPROPERTY()
	FOnUserInterfaceOpened OnUserInterfaceClosed;

protected:
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UImageButton* LoadMapImage = nullptr;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UTextButton* LoadMapText = nullptr;

	UPROPERTY()
	AWASPHUD* WASPHUD = nullptr;

private:
	virtual void NativeConstruct() override;
	virtual void NativeDestruct() override;
	virtual void NativeTick(
		const FGeometry& MyGeometry,
		float InDeltaTime) override;

	UFUNCTION()
	void LoadWorldMap();

	UFUNCTION()
	void LoadWorldMap2();
};
