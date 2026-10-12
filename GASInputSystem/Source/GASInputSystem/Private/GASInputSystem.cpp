// Copyright (c) 2026 Daniel Beaty. Part of the GAS Input System plugin, released under the MIT License. See LICENSE.

#include "GASInputSystem.h"

#define LOCTEXT_NAMESPACE "FGASInputSystemModule"

void FGASInputSystemModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
}

void FGASInputSystemModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FGASInputSystemModule, GASInputSystem)