// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <GameFramework/Actor.h>
#include "CoreMinimal.h"
#include "WASPActor.generated.h"

UCLASS()
class WASPDOME_API AWASPActor : public AActor
{
	GENERATED_BODY()

public:
	AWASPActor();

protected:
	virtual void PostLoad() override;
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* MeshComponent = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USkeletalMeshComponent* PlayerSkeletalMesh;
};
