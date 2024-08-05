// Fill out your copyright notice in the Description page of Project Settings.


#include "../Base/SNPlayerController.h"

#include "../Base/SNCargoBase.h"
#include "../Base/SNCargoGameMode.h"


bool ASNPlayerController::InputKey(const FInputKeyParams& Params)
{
	if (Params.Key == FKey("W") && Params.Event == IE_Pressed)
	{
		MoveForward();
	}
	else if (Params.Key == FKey("A") && Params.Event == IE_Pressed)
	{
		MoveLeft();
	}
	else if (Params.Key == FKey("S") && Params.Event == IE_Pressed)
	{
		MoveBackward();
	}
	else if (Params.Key == FKey("D") && Params.Event == IE_Pressed)
	{
		MoveRight();
	}
	else if (Params.Key == FKey("Q") && Params.Event == IE_Pressed)
	{

	}
	else if (Params.Key == FKey("E") && Params.Event == IE_Pressed)
	{

	}
	else if (Params.Key == FKey("Z") && Params.Event == IE_Pressed)
	{

	}
	else if (Params.Key == FKey("SpaceBar") && Params.Event == IE_Pressed)
	{
		SelectNext();
	}

	return Super::InputKey(Params);
}

void ASNPlayerController::BeginPlay()
{
	Super::BeginPlay();

	TArray<TSoftObjectPtr<ASNCargoBase>> Cargos = GetWorld()->GetAuthGameMode<ASNCargoGameMode>()->GetLoadedCargoActors();

	if (Cargos.Num() > 0)
	{
		SelectedCargo = Cargos[0];
		SelectedIndex = 0;
	}
}

void ASNPlayerController::MoveForward()
{
	SelectedCargo->SetCurrentPos(SelectedCargo->GetCurrentPos() + FVector(1, 0, 0));
}

void ASNPlayerController::MoveBackward()
{
	SelectedCargo->SetCurrentPos(SelectedCargo->GetCurrentPos() + FVector(-1, 0, 0));
}

void ASNPlayerController::MoveLeft()
{
	SelectedCargo->SetCurrentPos(SelectedCargo->GetCurrentPos() + FVector(0, -1, 0));
}

void ASNPlayerController::MoveRight()
{
	SelectedCargo->SetCurrentPos(SelectedCargo->GetCurrentPos() + FVector(0, 1, 0));
}

void ASNPlayerController::SelectNext()
{
	SelectNextCargo();
}

void ASNPlayerController::SelectNextCargo()
{
	TArray<TSoftObjectPtr<ASNCargoBase>> Cargos = GetWorld()->GetAuthGameMode<ASNCargoGameMode>()->GetLoadedCargoActors();

	int32 nextIndex = SelectedIndex + 1 >= Cargos.Num() ? 0 : SelectedIndex + 1;

	for (int i = 0; i < Cargos.Num(); i++)
	{
		if (i == nextIndex)
		{
			SelectedCargo = Cargos[i];
			SelectedIndex = nextIndex;

			return;
		}
	}
}
