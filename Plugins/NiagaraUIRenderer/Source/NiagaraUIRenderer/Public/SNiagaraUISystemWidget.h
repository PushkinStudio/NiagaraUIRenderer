// Copyright 2023 - Michal Smoleň

#pragma once

#include "NiagaraWidgetProperties.h"
#include "SlateMaterialBrush.h"
#include "Slate/SMeshWidget.h"

class UNiagaraUIComponent;
class UMaterialInterface;

/**
 * 
 */
class NIAGARAUIRENDERER_API SNiagaraUISystemWidget : public SMeshWidget
{	
public:
	SLATE_BEGIN_ARGS(SNiagaraUISystemWidget)
	{		
	}
	SLATE_END_ARGS()

	void Construct(const FArguments& Args);
	
	~SNiagaraUISystemWidget();

	virtual int32 OnPaint(const FPaintArgs& Args, const FGeometry& AllottedGeometry, const FSlateRect& MyCullingRect, FSlateWindowElementList& OutDrawElements, int32 LayerId, const FWidgetStyle& InWidgetStyle, bool bParentEnabled) const override;
	virtual FVector2D ComputeDesiredSize(float LayoutScaleMultiplier) const override;

	void AddRenderData(FSlateVertex** OutVertexData, SlateIndex** OutIndexData, UMaterialInterface* Material, int32 NumVertexData, int32 NumIndexData);
	
	void ClearRenderData();

	TSharedPtr<FSlateMaterialBrush> CreateSlateMaterialBrush(UMaterialInterface* Material);

	void CheckForInvalidBrushes();

	void SetNiagaraComponentReference(TWeakObjectPtr<UNiagaraUIComponent> NiagaraComponentIn, FNiagaraWidgetProperties Properties);

	void SetDesiredSize(FVector2D NewDesiredSize);

private:
	TWeakObjectPtr<UNiagaraUIComponent> NiagaraComponent;

	static TMap<UMaterialInterface*, TSharedPtr<FSlateMaterialBrush>> MaterialBrushMap;

	FNiagaraWidgetProperties WidgetProperties = FNiagaraWidgetProperties(nullptr, true, false, false, 1.f);

	FVector2D DesiredSize = FVector2D(256., 256.);
};
