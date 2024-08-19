// Fill out your copyright notice in the Description page of Project Settings.


#include "../Base/SNCargoBase.h"

#include "Engine/DataTable.h"
#include "Kismet/KismetSystemLibrary.h"
#include "UObject/ConstructorHelpers.h"


// Sets default values
ASNCargoBase::ASNCargoBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<UDataTable> CargoInfoDataObject(TEXT("/Game/Blueprint/DataTable/DT_CargoInfo"));
	if (CargoInfoDataObject.Succeeded())
	{
		CargoInfoDataTable = CargoInfoDataObject.Object;
	}
}

// Called when the game starts or when spawned
void ASNCargoBase::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ASNCargoBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (CargoInfoRowName.IsNone())
	{
		return;
	}

	FRotator curRot = GetForwardRotation();
	TArray<FVector> curPosInfos = GetCargoPosInfos();

	for (FVector v : curPosInfos)
	{
		FVector center = (curRot.RotateVector(v) + CurrentPos) * 100.0f;
		FVector extent = FVector::One() * 50.0f;

		UKismetSystemLibrary::DrawDebugBox(
			GetWorld(),
			center,
			extent,
			FLinearColor::Blue,
			FRotator::ZeroRotator,
			0.033f,
			1.5f
		);
	}
}

void ASNCargoBase::Init(FName RowName)
{
	CargoInfoRowName = RowName;

	FString contextString = TEXT("ASNCargoBase::BeginPlay FCargoInfo");
	CargoInfo = *CargoInfoDataTable->FindRow<FCargoInfo>(CargoInfoRowName, contextString);
}

void ASNCargoBase::Rotation(bool bIsLeft)
{
	CurrentRot += bIsLeft ? 1 : -1;

	if (CurrentRot > 3)
	{
		CurrentRot = 0;
	}
	else if (CurrentRot < 0)
	{
		CurrentRot = 3;
	}
}
