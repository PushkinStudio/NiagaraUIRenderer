// Copyright 2021 - Michal Smolen

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

class FNiagaraUIRendererModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};
