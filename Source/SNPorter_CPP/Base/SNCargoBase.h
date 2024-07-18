// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "../Struct/CargoInfo.h"

#include "SNCargoBase.generated.h"

class UDataTable;

UCLASS()
class SNPORTER_CPP_API ASNCargoBase : public AActor
{
	GENERATED_BODY()

public:	
	// Sets default values for this actor's properties
	ASNCargoBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void Init(FName RowName);

public:
	FORCEINLINE FRotator GetForwardRotation() { return FRotator(0.0f, 0.0f, CurrentRot * -90.0f); }
	FORCEINLINE TArray<FVector> GetCargoPosInfos() { return !CargoInfo.PosLaidInfos.IsEmpty() && bIsLaid ? CargoInfo.PosLaidInfos : CargoInfo.PosInfos; }

	FORCEINLINE void SetCurrentPos(FVector NewVector) { CurrentPos = NewVector; }

protected:
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "SNPorter")
	FName CargoInfoRowName;

	UPROPERTY(BlueprintReadWrite, Category = "SNPorter")
	FVector CurrentPos;

	UPROPERTY(BlueprintReadWrite, Category = "SNPorter")
	int CurrentRot = 1;

	UPROPERTY(BlueprintReadWrite, Category = "SNPorter")
	bool bIsLaid = false;

	UPROPERTY()
	class UDataTable* CargoInfoDataTable;

	UPROPERTY()
	FCargoInfo CargoInfo;
};
