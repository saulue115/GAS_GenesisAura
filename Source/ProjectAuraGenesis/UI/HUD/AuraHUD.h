// Copyright Saul Augusto Gasca Farrera

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "ProjectAuraGenesis/AbilitySystem/AuraAttributeSet.h"
#include "ProjectAuraGenesis/UI/WidgetControllers/OverlayWidgetController.h"
#include "ProjectAuraGenesis/UI/Widgets/AuraUserWidget.h"
#include "AuraHUD.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTAURAGENESIS_API AAuraHUD : public AHUD
{
	GENERATED_BODY()

public:

	UPROPERTY()
	TObjectPtr<UAuraUserWidget> OverlayWidget = nullptr;

	UFUNCTION()
	void InitOverlay(APlayerController* PC,APlayerState* PS,UAbilitySystemComponent* ASC,UAttributeSet* AS);

protected:

	UOverlayWidgetController* GetOverlayWidgetController(const FWidgetControllerParams& WCParams);
	
private:

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category=HUD,meta=(AllowPrivateAccess=true))
	TSubclassOf<UAuraUserWidget> OverlayWidgetClass;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category=HUD,meta=(AllowPrivateAccess=true))
	TObjectPtr<UOverlayWidgetController> OverlayWidgetController = nullptr;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category=HUD,meta=(AllowPrivateAccess=true))
	TSubclassOf<UOverlayWidgetController> OverlayWidgetControllerClass;

	
};
