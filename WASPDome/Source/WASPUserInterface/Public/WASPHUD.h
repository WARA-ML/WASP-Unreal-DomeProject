// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <GameFramework/HUD.h>
#include "WASPHUD.generated.h"

class UWASPUserInterfaceWidget;

/**
 * 
 */
UCLASS(Blueprintable)
class WASPUSERINTERFACE_API AWASPHUD
	: public AHUD
{
	GENERATED_BODY()

public:
	AWASPHUD();
	virtual ~AWASPHUD() override;

	UFUNCTION()
	UWASPUserInterfaceWidget* GetUserWidgetInterface() const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (BindWidget))
	TSubclassOf<UWASPUserInterfaceWidget> UserInterfaceWidgetBP = nullptr;

protected:
	virtual void BeginPlay() override;

	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

private:
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget), meta = (AllowPrivateAccess = "true"))
	UWASPUserInterfaceWidget* UserInterfaceWidget = nullptr;
};
