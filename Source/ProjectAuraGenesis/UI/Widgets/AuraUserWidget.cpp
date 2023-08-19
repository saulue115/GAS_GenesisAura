// Copyright Saul Augusto Gasca Farrera


#include "AuraUserWidget.h"
#include "Slate/SObjectWidget.h"
#include "Blueprint/WidgetBlueprintLibrary.h"
#include "Slate/SlateBrushAsset.h"
#include "Kismet/KismetMathLibrary.h"


void UAuraUserWidget::NativePreConstruct()
{
	Super::NativePreConstruct();

	UpdateBoxSize();

	UpdateBackgroundBrush();


	UpdateGlobeImage();

	UpdateGlobePadding();

	UpdateGlassBrush();

	UpdateGlassPadding();
	
}

void UAuraUserWidget::SetWidgetController(UObject* InWidgetController)
{
	WidgetController = InWidgetController;
	WidgetControllerSet();
}



void UAuraUserWidget::UpdateBoxSize()
{
	// USizeBox* SizeBoxRoot = NewObject<USizeBox>(this);


	USizeBox* SizeBoxRoot = Cast<USizeBox>(GetWidgetFromName("SizeBox_Root"));
	if(!SizeBoxRoot) return;

	SizeBoxRoot->SetWidthOverride(BoxWidth);

	SizeBoxRoot->SetHeightOverride(BoxHeight);
	
	
}

void UAuraUserWidget::UpdateBackgroundBrush()
{
	//UImage* ImageBackground2 = NewObject<UImage>(this);
	// Obtener el valor de la variable de Blueprint "Image_Background"
	UImage* ImageBackground2 = Cast<UImage>(GetWidgetFromName("Image_Background"));

	if(!ImageBackground2) return;
	
	ImageBackground2->SetBrush(BackgroundBrush2);
}

void UAuraUserWidget::UpdateGlobeImage()
{
	// Crea el estilo para el ProgressBar y Slate bush
	FProgressBarStyle ProgressBarStyle;
	FSlateBrush SlateBrush;
	
	ProgressBar = Cast<UProgressBar>(GetWidgetFromName("ProgressBar_Globe"));

	if(!ProgressBar) return;

	SlateBrush.TintColor = FSlateColor(FLinearColor(1.0f, 0.0f, 1.0f, 0.0f)); // Alfa 0
	ProgressBarStyle.SetBackgroundImage(SlateBrush);
	ProgressBarStyle.SetFillImage(ProgressBarFillImage);

	ProgressBar->SetWidgetStyle(ProgressBarStyle);
}

void UAuraUserWidget::UpdateGlobePadding()
{
	ProgressBar = Cast<UProgressBar>(GetWidgetFromName("ProgressBar_Globe"));

	if(!ProgressBar) return;

	OverlaySlot = Cast<UOverlaySlot>(ProgressBar->Slot);

	if(!OverlaySlot) return;

	OverlaySlot->SetPadding(FMargin(GlobePadding));
}

void UAuraUserWidget::UpdateGlassBrush()
{
	GlassImage = Cast<UImage>(GetWidgetFromName("Image_Glass"));

	if(!GlassImage) return;

	GlassImage->SetBrush(GlassBrush2);
}

void UAuraUserWidget::UpdateGlassPadding()
{
	GlassImage = Cast<UImage>(GetWidgetFromName("Image_Glass"));

	if(!GlassImage) return;

	OverlaySlot = Cast<UOverlaySlot>(GlassImage->Slot);

	if(!OverlaySlot) return;

	OverlaySlot->SetPadding(FMargin(GlobePadding));
	
}




#pragma region Overlay Globe Controller Functions

void UAuraUserWidget::CheckProgressBarPercent(const float& MinValue,const float& MaxValue)
{
	ProgressBar = Cast<UProgressBar>(GetWidgetFromName("ProgressBar_Globe"));

	if(!ProgressBar) return;
	
	ProgressBar->SetPercent(UKismetMathLibrary::SafeDivide(MinValue,MaxValue));
}


void UAuraUserWidget::CastToBlueprint()
{
	OverlayWidgetControllerClass = Cast<UOverlayWidgetController>(WidgetController);

	if(!OverlayWidgetControllerClass) return;
	
	OverlayWidgetControllerClass->OnManaChanged.AddDynamic(this,&UAuraUserWidget::GetSafeMana);
	OverlayWidgetControllerClass->OnMaxManaChanged.AddDynamic(this,&UAuraUserWidget::GetSafeMaxMana);
		
	
}



void UAuraUserWidget::ListeningHealthAttributes()
{

	OverlayWidgetControllerClass = Cast<UOverlayWidgetController>(WidgetController);

	if(!OverlayWidgetControllerClass) return;
	
	OverlayWidgetControllerClass->OnHealthChanged.AddDynamic(this,&UAuraUserWidget::GetSafeHealth);
	OverlayWidgetControllerClass->OnMaxHealthChanged.AddDynamic(this,&UAuraUserWidget::GetSafeMaxHealth);

}

void UAuraUserWidget::ListeningManaAttributes()
{
	OverlayWidgetControllerClass = Cast<UOverlayWidgetController>(WidgetController);

	if(!OverlayWidgetControllerClass) return;
	
	OverlayWidgetControllerClass->OnManaChanged.AddDynamic(this,&UAuraUserWidget::GetSafeMana);
	OverlayWidgetControllerClass->OnMaxManaChanged.AddDynamic(this,&UAuraUserWidget::GetSafeMaxMana);
}


void UAuraUserWidget::GetSafeHealth(float NewHealth)
{
	Health = NewHealth;

	CheckProgressBarPercent(Health,MaxHealth);
}

void UAuraUserWidget::GetSafeMaxHealth(float NewMaxHealth)
{
	MaxHealth = NewMaxHealth;


	CheckProgressBarPercent(Health,MaxHealth);
}

void UAuraUserWidget::GetSafeMana(float NewMana)
{
	Mana = NewMana;
	
	CheckProgressBarPercent(Mana,MaxMana);
}

void UAuraUserWidget::GetSafeMaxMana(float NewMaxMana)
{
	MaxMana = NewMaxMana;

	CheckProgressBarPercent(Mana,MaxMana);
}


#pragma endregion


