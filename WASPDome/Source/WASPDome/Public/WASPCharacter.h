// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <GameFramework/Character.h>
#include "CoreMinimal.h"
#include "WASPCharacter.generated.h"

class UInputMappingContext;
class UInputAction;
struct FInputActionValue;

UCLASS()
class WASPDOME_API AWASPCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AWASPCharacter();

	UInputMappingContext* GetCharacterMappingContext() const;

	void AddInputMappingContext();

	void RemoveInputMappingContext();

private:
	UFUNCTION(BlueprintCallable, Category= "Input")
	void MoveForward(const FInputActionValue& Value);

	UFUNCTION(BlueprintCallable, Category= "Input")
	void MoveRight(const FInputActionValue& Value);

	UFUNCTION(BlueprintCallable, Category= "Input")
	void MoveUp(const FInputActionValue& Value);

	UFUNCTION(BlueprintCallable, Category= "Input")
	void Turn(const FInputActionValue& Value);

	UFUNCTION(BlueprintCallable, Category= "Input")
	void LookUp(const FInputActionValue& Value);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input", meta = (AllowPrivateAccess = "true"))
	UInputMappingContext* CharacterMappingContext;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input", meta = (AllowPrivateAccess = "true"))
	UInputAction* Ia_MoveForward;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input", meta = (AllowPrivateAccess = "true"))
	UInputAction* Ia_MoveRight;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input", meta = (AllowPrivateAccess = "true"))
	UInputAction* Ia_MoveUp;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input", meta = (AllowPrivateAccess = "true"))
	UInputAction* Ia_Turn;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input", meta = (AllowPrivateAccess = "true"))
	UInputAction* Ia_LookUp;

protected:
	virtual void BeginPlay() override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
