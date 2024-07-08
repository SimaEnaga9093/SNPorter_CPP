// Fill out your copyright notice in the Description page of Project Settings.


#include "Base/CargoBaseActor.h"

// Sets default values
ACargoBaseActor::ACargoBaseActor()
{
  // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
  PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACargoBaseActor::BeginPlay()
{
  Super::BeginPlay();

}

// Called every frame
void ACargoBaseActor::Tick(float DeltaTime)
{
  Super::Tick(DeltaTime);

}

