// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"

#include "SNCargoGameMode.generated.h"

/**
 * 
 */
UCLASS()
class SNPORTER_CPP_API ASNCargoGameMode : public AGameModeBase
{
	GENERATED_BODY()

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "SNPorter")
	FVector CargoSize;

	UPROPERTY(BlueprintReadWrite, Category = "SNPorter")
	TMap<FVector, int> LoadedCargoInfo;
};
