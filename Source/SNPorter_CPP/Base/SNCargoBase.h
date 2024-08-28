// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "../Struct/CargoInfo.h"

#include "SNCargoBase.generated.h"

class UDataTable;
class ASNBlockBase;

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

public:
	void Init(FName RowName);
	void Move(FVector AddedVector);
	void Rotation(bool bIsLeft);
	void Lay(bool NewIsLaid);
	TArray<FVector> GetCurrentCargoPosInfos();

	FORCEINLINE FRotator GetForwardRotation() { return FRotator(0.0f, CurrentRot * -90.0f, 0.0f); }
	FORCEINLINE TArray<FVector> GetCargoPosInfos() { return !CargoInfo.PosLaidInfos.IsEmpty() && bIsLaid ? CargoInfo.PosLaidInfos : CargoInfo.PosInfos; }

	//FORCEINLINE void SetCurrentPos(FVector NewVector) { CurrentPos = NewVector; }
	FORCEINLINE FVector GetCurrentPos() { return CurrentPos; }

	FORCEINLINE void SetIsLaid(bool NewIsLaid) { bIsLaid = NewIsLaid; }
	FORCEINLINE bool GetIsLaid() { return bIsLaid; }

	FORCEINLINE FCargoInfo GetCargoInfo() { return CargoInfo; }

protected:
	void UpdatePosInfos();

protected:
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "SNPorter")
	FName CargoInfoRowName;

	UPROPERTY(BlueprintReadWrite, Category = "SNPorter")
	FVector CurrentPos;

	UPROPERTY(BlueprintReadWrite, Category = "SNPorter")
	int CurrentRot = 1;

	UPROPERTY(BlueprintReadWrite, Category = "SNPorter")
	bool bIsLaid = false;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "SNPorter")
	TSubclassOf<class ASNBlockBase> BlockBaseClass;

	UPROPERTY()
	class UDataTable* CargoInfoDataTable;

	UPROPERTY()
	FCargoInfo CargoInfo;

	UPROPERTY()
	TArray<TSoftObjectPtr<ASNBlockBase>> BlockActors;
};
