// Copyright (c) 2026 Daniel Beaty. Part of the GAS Input System plugin, released under the MIT License. See LICENSE.

#pragma once

#include "Modules/ModuleManager.h"

class FGASInputSystemModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};
