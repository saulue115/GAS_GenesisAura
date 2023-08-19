// Copyright Saul Augusto Gasca Farrera

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Image.h"
#include "Components/SizeBox.h"
#include "Components/ProgressBar.h"
#include "Components/OverlaySlot.h"
#include "ProjectAuraGenesis/UI/WidgetControllers/OverlayWidgetController.h"
#include "AuraUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTAURAGENESIS_API UAuraUserWidget : public UUserWidget
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable)
	void SetWidgetController(UObject* InWidgetController);

	UPROPERTY(BlueprintReadWrite)
	TObjectPtr<UObject> WidgetController;

protected:

	UFUNCTION(BlueprintImplementableEvent)
	void WidgetControllerSet();


	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category=Globe)
	float BoxHeight  = 250.0f;


	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category=Globe)
	float BoxWidth  = 250.0f;

	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category=Globe)
	float GlobePadding  = 10.0f;


	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category=Globe)
	FSlateBrush ProgressBarFillImage;


	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category=Globe)
	FSlateBrush BackgroundBrush2;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category=Globe)
	FSlateBrush GlassBrush2;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category=Globe)
	UProgressBar* ProgressBar;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category=Globe)
	UImage* GlassImage;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category=Globe)
	UOverlaySlot* OverlaySlot;


	//Overlay Widget Controller to Blueprints
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category=UIAura)
	TObjectPtr<UOverlayWidgetController> OverlayWidgetControllerClass;


	//Health Globe
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category=UIAura)
	float Health = 0.0f;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category=UIAura)
	float MaxHealth = 0.0f;


	//Mana Globe
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category=UIAura)
	float Mana = 0.0f;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category=UIAura)
	float MaxMana = 0.0f;

public:

	virtual  void NativePreConstruct() override;


	UFUNCTION(BlueprintCallable,Category=GlobeUI)
	void UpdateBoxSize();

	UFUNCTION(BlueprintCallable,Category=GlobeUI)
	void UpdateBackgroundBrush();

	UFUNCTION(BlueprintCallable,Category=GlobeUI)
	void UpdateGlobeImage();


	UFUNCTION(BlueprintCallable,Category=GlobeUI)
	void UpdateGlobePadding();
	

	UFUNCTION(BlueprintCallable,Category=GlobeUI)
	void UpdateGlassBrush();


	UFUNCTION(BlueprintCallable,Category=GlobeUI)
	void UpdateGlassPadding();




	//Listen Attributes with mana and health functions


	UFUNCTION()
	void CheckProgressBarPercent(const float& MinValue,const float& MaxValue);
	
	UFUNCTION(BlueprintCallable,Category=GlobeUI)
	void CastToBlueprint();


	UFUNCTION(BlueprintCallable,Category=GlobeUI)
	void ListeningManaAttributes();

	UFUNCTION(BlueprintCallable,Category=UIAura)
	void ListeningHealthAttributes();

	UFUNCTION(BlueprintCallable,Category=UIAura)
	void GetSafeHealth(float NewHealth);

	UFUNCTION(BlueprintCallable,Category=UIAura)
	void GetSafeMaxHealth(float NewMaxHealth);


	UFUNCTION(BlueprintCallable,Category=UIAura)
	void GetSafeMana(float NewMana);

	UFUNCTION(BlueprintCallable,Category=UIAura)
	void GetSafeMaxMana(float NewMaxMana);
};
