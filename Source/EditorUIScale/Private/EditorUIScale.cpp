// Copyright Epic Games, Inc. All Rights Reserved.

#include "EditorUIScale.h"
#include "EditorUIScaleSettings.h"

#define LOCTEXT_NAMESPACE "FEditorUIScaleModule"

void FEditorUIScaleModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module

	FSlateApplication::Get().SetApplicationScale(GetDefault<UEditorUIScaleSettings>()->UIScale);

}

void FEditorUIScaleModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FEditorUIScaleModule, EditorUIScale)