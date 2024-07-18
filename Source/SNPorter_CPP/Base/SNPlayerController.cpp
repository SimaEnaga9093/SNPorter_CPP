// Fill out your copyright notice in the Description page of Project Settings.


#include "../Base/SNPlayerController.h"


bool ASNPlayerController::InputKey(const FInputKeyParams& Params)
{
	if (Params.Key == FKey("W") && Params.Event == IE_Pressed)
	{

	}
	else if (Params.Key == FKey("A") && Params.Event == IE_Pressed)
	{

	}
	else if (Params.Key == FKey("S") && Params.Event == IE_Pressed)
	{

	}
	else if (Params.Key == FKey("D") && Params.Event == IE_Pressed)
	{

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

	}

	return Super::InputKey(Params);
}

void ASNPlayerController::BeginPlay()
{
	Super::BeginPlay();

}