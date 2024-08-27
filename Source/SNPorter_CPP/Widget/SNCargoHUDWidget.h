// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Blueprint/UserWidget.h"
#include "CoreMinimal.h"

#include "../Widget/SNUserWidget.h"

#include "SNCargoHUDWidget.generated.h"

class UTextBlock;

/**
 * 
 */
UCLASS()
class SNPORTER_CPP_API USNCargoHUDWidget : public USNUserWidget
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TSoftObjectPtr<UTextBlock> TextCargoName;

public:
	UFUNCTION()
	void SetCargoNameText(const FText& Text);

};
