// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"

#include "SNCargoGameMode.generated.h"

class ASNCargoBase;

/**
 * 
 */
UCLASS()
class SNPORTER_CPP_API ASNCargoGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	FORCEINLINE TArray<TSoftObjectPtr<ASNCargoBase>> GetLoadedCargoActors() { return LoadedCargoActors; }

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "SNPorter")
	FVector CargoSize;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "SNPorter")
	TArray<FName> LoadedCargoName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "SNPorter")
	float BlockOffsetSize = 100.0f;

	UPROPERTY(BlueprintReadWrite, Category = "SNPorter")
	TMap<FVector, int> LoadedPosInfos;

	UPROPERTY(BlueprintReadWrite, Category = "SNPorter")
	TArray<TSoftObjectPtr<ASNCargoBase>> LoadedCargoActors;
};
