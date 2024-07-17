// Fill out your copyright notice in the Description page of Project Settings.


#include "../Base/SNCargoGameMode.h"

void ASNCargoGameMode::BeginPlay()
{
    for (int x = 0; x < CargoSize.X; x++)
    {
        for (int y = 0; y < CargoSize.Y; y++)
        {
            for (int z = 0; z < CargoSize.Z; z++)
            {
                LoadedCargoInfo.Add(FVector(x, y, z), -1);
            }
        }
    }
}
