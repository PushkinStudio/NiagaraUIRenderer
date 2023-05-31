// Copyright (c) 2021 Michal Smolen 

#pragma once

#include "CoreMinimal.h"

#include "Classes/EditorStyleSettings.h"
#include "Styling/SlateStyle.h"
#include "Styling/SlateTypes.h"

/**
 * 
 */
class NIAGARAUIRENDEREREDITOR_API FNiagaraUIRendererEditorStyle
{
public:
	static void Initialize();

	static void Shutdown();

	static TSharedPtr<class ISlateStyle> Get();

	static FName GetStyleSetName();

	static const FSlateBrush* GetBrush( FName PropertyName, const ANSICHAR* Specifier = NULL )
	{
		return StyleSet->GetBrush( PropertyName, Specifier);
	}

	const static FColor WarningBoxComplementaryColor;
	
private:
	static FString InContent(const FString& RelativePath, const ANSICHAR* Extension);
	
	class FStyle : public FSlateStyleSet
	{
	public:
		FStyle(const FName& InStyleSetName);
		
		FButtonStyle IgnoreButton;
		FButtonStyle IgnoreButtonFix;
		FButtonStyle AutoPopulateButton;
		FTextBlockStyle IgnoreButtonText;
	};
	
	static TSharedPtr<FNiagaraUIRendererEditorStyle::FStyle> StyleSet;
};
