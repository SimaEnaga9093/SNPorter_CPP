// Fill out your copyright notice in the Description page of Project Settings.


#include "../Base/SNCargoBase.h"

#include "Engine/DataTable.h"
#include "Kismet/KismetSystemLibrary.h"
#include "UObject/ConstructorHelpers.h"

#include "../Base/SNBlockBase.h"

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

	FString contextString = TEXT("ASNCargoBase::Init FCargoInfo");
	CargoInfo = *CargoInfoDataTable->FindRow<FCargoInfo>(CargoInfoRowName, contextString);

	FActorSpawnParameters params;
	params.Owner = this;
	params.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	for (FVector v : CargoInfo.PosInfos)
	{
		ASNBlockBase* SpawnedActor = GetWorld()->SpawnActor<ASNBlockBase>(BlockBaseClass, params);
		BlockActors.Add(SpawnedActor);
	}

	UpdatePosInfos();
}

void ASNCargoBase::Move(FVector AddedVector)
{
	CurrentPos += AddedVector;

	UpdatePosInfos();
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

	UpdatePosInfos();
}

void ASNCargoBase::Lay(bool NewIsLaid)
{
	bIsLaid = NewIsLaid;

	UpdatePosInfos();
}

TArray<FVector> ASNCargoBase::GetCurrentCargoPosInfos()
{
	TArray<FVector> infos;
	for (FVector v : GetCargoPosInfos())
	{
		FVector newVector = FVector();
		switch (CurrentRot)
		{
		case 0: // 0
			newVector = v;

			break;
		case 1: // 90
			newVector = FVector((int)v.Y, (int)v.X * -1, (int)v.Z);

			break;
		case 2: // 180
			newVector = FVector((int)v.X * -1, (int)v.Y * -1, (int)v.Z);

			break;
		case 3: // 270
			newVector = FVector((int)v.Y * -1, (int)v.X, (int)v.Z);

			break;
		}

		infos.Add(CurrentPos + newVector);
	}

	return infos;
}

void ASNCargoBase::UpdatePosInfos()
{
	TArray<FVector> infos = GetCurrentCargoPosInfos();

	for (int i = 0; i < infos.Num(); i++)
	{
		BlockActors[i]->SetActorLocation(infos[i] * 100);
	}
}
