// Fill out your copyright notice in the Description page of Project Settings.


#include "../Base/SNCargoGameMode.h"

#include "Kismet/GameplayStatics.h"

#include "../Base/SNCargoBase.h"

void ASNCargoGameMode::BeginPlay()
{
	Super::BeginPlay();

	for (int x = 0; x < CargoSize.X; x++)
	{
		for (int y = 0; y < CargoSize.Y; y++)
		{
			for (int z = 0; z < CargoSize.Z; z++)
			{
				LoadedPosInfos.Add(FVector(x, y, z), -1);

				DrawDebugBox(GetWorld(), FVector(x, y, z) * BlockOffsetSize, FVector(BlockOffsetSize / 2), FColor::Black, true);
			}
		}
	}

	UGameplayStatics::GetPlayerPawn(this, 0)->TeleportTo((CargoSize - FVector::One()) * BlockOffsetSize / 2, FRotator::ZeroRotator, false, false);

	for (int i = 0; i < LoadedCargoName.Num(); i++)
	{
		ASNCargoBase* SpawnedActor = GetWorld()->SpawnActor<ASNCargoBase>(ASNCargoBase::StaticClass());
		SpawnedActor->Init(LoadedCargoName[i]);
		LoadedCargoActors.Add(SpawnedActor);
	}
}
