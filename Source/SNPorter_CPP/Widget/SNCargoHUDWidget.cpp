// Fill out your copyright notice in the Description page of Project Settings.


#include "../Widget/SNCargoHUDWidget.h"

#include "Components/TextBlock.h"

void USNCargoHUDWidget::SetCargoNameText(const FText& Text)
{
	if (TextCargoName != nullptr)
	{
		TextCargoName->SetText(Text);
	}
}
