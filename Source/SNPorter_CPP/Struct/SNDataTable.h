// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "UObject/NoExportTypes.h"

#include "SNDataTable.generated.h"

/**
 * 
 */
UCLASS()
class SNPORTER_CPP_API USNDataTable : public UObject
{
	GENERATED_BODY()
	
public:
	UPROPERTY(BlueprintReadWrite, Category = "SNPorter")
	FTableRowBase CargoInfo;
};
