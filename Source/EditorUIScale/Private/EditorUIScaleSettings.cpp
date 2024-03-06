// Fill out your copyright notice in the Description page of Project Settings.


#include "EditorUIScaleSettings.h"


void UEditorUIScaleSettings::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);

	if (PropertyChangedEvent.GetPropertyName() == "UIScale" && !FEditorUIScaleModule::CheckIsImmersiveModeEnabled())
	{
		FSlateApplication::Get().SetApplicationScale(UIScale);
		SaveConfig();
	}

}
