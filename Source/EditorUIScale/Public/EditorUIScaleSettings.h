// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "EditorUIScale.h"
#include "EditorUIScaleSettings.generated.h"

/**
 * 
 */
UCLASS(Config = EditorPerProjectUserSettings, meta = (DisplayName = "Scale Editor UI"))
class EDITORUISCALE_API UEditorUIScaleSettings : public UDeveloperSettings
{
	GENERATED_BODY()

public:
	explicit UEditorUIScaleSettings(const FObjectInitializer& ObjectInitializer) : UDeveloperSettings(ObjectInitializer)
	{
		UIScale = 1.0f;
		LoadConfig();
	}

	virtual FName GetCategoryName() const override { return "Plugins"; }

	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;

	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "General", meta = (ClampMin = 0.5f, ClampMax = 3.0f))
	float UIScale;
};
