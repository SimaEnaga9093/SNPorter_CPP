// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"

#include "SNPlayerController.generated.h"

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


};
