// Copyright Saul Augusto Gasca Farrera

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Image.h"
#include "Components/SizeBox.h"
#include "Components/ProgressBar.h"
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


public:

	virtual  void NativePreConstruct() override;


	UFUNCTION(BlueprintCallable,Category=GlobeUI)
	void UpdateBoxSize2();

	UFUNCTION(BlueprintCallable,Category=GlobeUI)
	void UpdateBackgroundBrush2();

	UFUNCTION(BlueprintCallable,Category=GlobeUI)
	void UpdateGlobeImage2();
	
};
