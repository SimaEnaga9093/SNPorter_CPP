// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"

#include "SNPlayerController.generated.h"

class ASNCargoBase;

/**
 * 
 */
UCLASS()
class SNPORTER_CPP_API ASNPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	virtual bool InputKey(const FInputKeyParams& Params) override;

protected:
	virtual void BeginPlay() override;

	void MoveForward();
	void MoveBackward();
	void MoveLeft();
	void MoveRight();
	void TurnLeft();
	void TurnRight();
	void LayCargo();
	void SelectNext();

	void SelectNextCargo();

protected:
	UPROPERTY(BlueprintReadWrite, Category = "SNPorter")
	TSoftObjectPtr<ASNCargoBase> SelectedCargo;

	UPROPERTY(BlueprintReadWrite, Category = "SNPorter")
	int SelectedIndex;
};
