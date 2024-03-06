// Copyright Epic Games, Inc. All Rights Reserved.

#include "EditorUIScale.h"
#include "EditorUIScaleSettings.h"
#include "LevelEditor.h" 
#include "SLevelViewport.h" 

#define LOCTEXT_NAMESPACE "FEditorUIScaleModule"

void FEditorUIScaleModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	FSlateApplication::Get().SetApplicationScale(GetDefault<UEditorUIScaleSettings>()->UIScale);

	// Creating and regestering a delegate to tick
	TickDelegate = FTickerDelegate::CreateRaw(this, &FEditorUIScaleModule::Tick);
	TickDelegateHandle = FTSTicker::GetCoreTicker().AddTicker(TickDelegate);

}

// This function will be called every frame
// Checks if level editor is in immersive mode and sets the application scale accordingly (thanks @kroaton)
// not good for performance but it works
// @todo use delegate event method maybe?
bool FEditorUIScaleModule::Tick(float DeltaTime)
{
	bool isImmersive = CheckIsImmersiveModeEnabled();

	isImmersive ? FSlateApplication::Get().SetApplicationScale(1.0f) : FSlateApplication::Get().SetApplicationScale(GetDefault<UEditorUIScaleSettings>()->UIScale);
	return true;
}

// Check if level editor is in immersive (fullscreen) mode
bool FEditorUIScaleModule::CheckIsImmersiveModeEnabled()
{
	FLevelEditorModule* LevelEditorModule = FModuleManager::GetModulePtr<FLevelEditorModule>("LevelEditor");

	if (LevelEditorModule != nullptr)
	{
		return LevelEditorModule->GetFirstActiveViewport()->IsImmersive();
	}

	return false;
}

void FEditorUIScaleModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.

	FTSTicker::GetCoreTicker().RemoveTicker(TickDelegateHandle);
}


#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FEditorUIScaleModule, EditorUIScale)