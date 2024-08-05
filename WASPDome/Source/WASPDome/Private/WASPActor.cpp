// Fill out your copyright notice in the Description page of Project Settings.


#include "WASPDome/Public/WASPActor.h"


// Sets default values
AWASPActor::AWASPActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	PlayerSkeletalMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SkeletalMeshComponent"));
	RootComponent = PlayerSkeletalMesh;

	// Set the mesh (you can replace the path with your actual mesh path)
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> MeshAsset(
		TEXT("/Game/Characters/Harold/Harold_fixed.Harold_fixed"));

	if (MeshAsset.Succeeded())
	{
		PlayerSkeletalMesh->SetSkeletalMesh(MeshAsset.Object);
	}
}

void AWASPActor::PostLoad()
{
	Super::PostLoad();
}

// Called when the game starts or when spawned
void AWASPActor::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AWASPActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
