// Copyright Saul Augusto Gasca Farrera


#include "AuraUserWidget.h"
#include "Slate/SObjectWidget.h"
#include "Blueprint/WidgetBlueprintLibrary.h"
#include "Slate/SlateBrushAsset.h"


void UAuraUserWidget::NativePreConstruct()
{
	Super::NativePreConstruct();

	UpdateBoxSize2();

	UpdateBackgroundBrush2();


	UpdateGlobeImage2();
	
}

void UAuraUserWidget::SetWidgetController(UObject* InWidgetController)
{
	WidgetController = InWidgetController;
	WidgetControllerSet();
}



void UAuraUserWidget::UpdateBoxSize2()
{
	// USizeBox* SizeBoxRoot = NewObject<USizeBox>(this);


	USizeBox* SizeBoxRoot = Cast<USizeBox>(GetWidgetFromName("SizeBox_Root"));
	if(!SizeBoxRoot) return;

	SizeBoxRoot->SetWidthOverride(BoxWidth);

	SizeBoxRoot->SetHeightOverride(BoxHeight);

	


	
}

void UAuraUserWidget::UpdateBackgroundBrush2()
{
	//UImage* ImageBackground2 = NewObject<UImage>(this);
	// Obtener el valor de la variable de Blueprint "Image_Background"
	UImage* ImageBackground2 = Cast<UImage>(GetWidgetFromName("Image_Background"));

	if(!ImageBackground2) return;
	
	ImageBackground2->SetBrush(BackgroundBrush2);
}

void UAuraUserWidget::UpdateGlobeImage2()
{
	// Crea el estilo para el ProgressBar y Slate bush
	FProgressBarStyle ProgressBarStyle;
	FSlateBrush SlateBrush;
	
	UProgressBar* ProgressBar = Cast<UProgressBar>(GetWidgetFromName("ProgressBar_Globe"));

	if(!ProgressBar) return;

	SlateBrush.TintColor = FSlateColor(FLinearColor(1.0f, 0.0f, 1.0f, 0.0f)); // Alfa 0
	ProgressBarStyle.SetBackgroundImage(SlateBrush);
	ProgressBarStyle.SetFillImage(ProgressBarFillImage);

	ProgressBar->SetWidgetStyle(ProgressBarStyle);
}
