// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "CargoGameModeBase.generated.h"

/**
 *
 */
UCLASS()
class SNPORTER_CPP_API ACargoGameModeBase : public AGameModeBase
{
  GENERATED_BODY()

public:
    TMap<FVector, TSoftObjectPtr<AActor>> LoadedCargos;

public:
    void SummitCargoToPos(TSoftObjectPtr<AActor> TargetActor, FVector TargetPos);
};
