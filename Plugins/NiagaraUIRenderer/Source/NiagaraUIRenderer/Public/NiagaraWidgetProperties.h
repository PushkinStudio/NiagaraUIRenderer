﻿// Copyright 2021 - Michal Smolen

#pragma once

#include "CoreMinimal.h"

class UMaterialInterface;

struct FNiagaraWidgetProperties
{
	FNiagaraWidgetProperties();
	FNiagaraWidgetProperties(TMap<UMaterialInterface*, UMaterialInterface*>* inRemapList, bool inAutoActivate, bool inShowDebugSystem, bool inFakeDepthScale, float inFakeDepthDistance)
        : MaterialRemapList(inRemapList), AutoActivate(inAutoActivate), ShowDebugSystemInWorld(inShowDebugSystem), FakeDepthScale(inFakeDepthScale), FakeDepthScaleDistance(inFakeDepthDistance) {}
	
	TMap<UMaterialInterface*, UMaterialInterface*>* MaterialRemapList = nullptr;
	bool AutoActivate = true;
	bool ShowDebugSystemInWorld = false;
	bool FakeDepthScale = false;
	float FakeDepthScaleDistance = 1000.f;
};
