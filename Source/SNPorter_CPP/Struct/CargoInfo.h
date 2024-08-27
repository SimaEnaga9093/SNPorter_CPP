// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"

#include "CargoInfo.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct SNPORTER_CPP_API FCargoInfo : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FText Name;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TArray<FVector> PosInfos;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TArray<FVector> PosLaidInfos;
};
