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
		TurnLeft();
	}
	else if (Params.Key == FKey("E") && Params.Event == IE_Pressed)
	{
		TurnRight();
	}
	else if (Params.Key == FKey("Z") && Params.Event == IE_Pressed)
	{
		LayCargo();
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
	FVector NewPos = SelectedCargo->GetCurrentPos() + FVector(1, 0, 0);
	if (GetWorld()->GetAuthGameMode<ASNCargoGameMode>()->IsValidPos(NewPos))
	{
		SelectedCargo->SetCurrentPos(NewPos);
	}
}

void ASNPlayerController::MoveBackward()
{
	FVector NewPos = SelectedCargo->GetCurrentPos() + FVector(-1, 0, 0);
	if (GetWorld()->GetAuthGameMode<ASNCargoGameMode>()->IsValidPos(NewPos))
	{
		SelectedCargo->SetCurrentPos(NewPos);
	}
}

void ASNPlayerController::MoveLeft()
{
	FVector NewPos = SelectedCargo->GetCurrentPos() + FVector(0, -1, 0);
	if (GetWorld()->GetAuthGameMode<ASNCargoGameMode>()->IsValidPos(NewPos))
	{
		SelectedCargo->SetCurrentPos(NewPos);
	}
}

void ASNPlayerController::MoveRight()
{
	FVector NewPos = SelectedCargo->GetCurrentPos() + FVector(0, 1, 0);
	if (GetWorld()->GetAuthGameMode<ASNCargoGameMode>()->IsValidPos(NewPos))
	{
		SelectedCargo->SetCurrentPos(NewPos);
	}
}

void ASNPlayerController::TurnLeft()
{
	SelectedCargo->Rotation(true);
}

void ASNPlayerController::TurnRight()
{
	SelectedCargo->Rotation(false);
}

void ASNPlayerController::LayCargo()
{
	SelectedCargo->SetIsLaid(!SelectedCargo->GetIsLaid());
}

void ASNPlayerController::SelectNext()
{
	bool bIsSuccess = GetWorld()->GetAuthGameMode<ASNCargoGameMode>()->SummitCargo(SelectedIndex);
	if (bIsSuccess)
	{
		SelectNextCargo();
	}
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
