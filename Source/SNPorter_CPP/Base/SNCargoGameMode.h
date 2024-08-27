// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"

#include "SNCargoGameMode.generated.h"

class ASNCargoBase;
class USNCargoHUDWidget;

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

public:
	bool SummitCargo(int CargoIndex);

	FORCEINLINE TArray<TSoftObjectPtr<ASNCargoBase>> GetLoadedCargoActors() { return LoadedCargoActors; }
	FORCEINLINE bool IsValidPos(FVector TargetPos) { return LoadedPosInfos.Find(TargetPos) != nullptr; }

public:
	UPROPERTY()
	TSoftObjectPtr<USNCargoHUDWidget> HUDWidget;

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

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "SNPorter")
	TSubclassOf<USNCargoHUDWidget> HUDWidgetClass;

};
