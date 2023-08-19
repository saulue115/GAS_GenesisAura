// Copyright Saul Augusto Gasca Farrera


#include "AuraHUD.h"


UOverlayWidgetController* AAuraHUD::GetOverlayWidgetController(const FWidgetControllerParams& WCParams)
{
	if(!OverlayWidgetControllerClass) return nullptr;

	OverlayWidgetController = NewObject<UOverlayWidgetController>(this,OverlayWidgetControllerClass);
	OverlayWidgetController->SetWidgetControllerParams(WCParams);
	OverlayWidgetController->BindCallbacksToDependencies();

	return OverlayWidgetController;
}

void AAuraHUD::InitOverlay(APlayerController* PC, APlayerState* PS, UAbilitySystemComponent* ASC, UAttributeSet* AS)
{
	if(!GetWorld()) return;

	checkf(OverlayWidgetClass,TEXT("Overlay Widget Class uninitialized,please fill out AuraHUD_BP"));

	checkf(OverlayWidgetControllerClass,TEXT("Overlay Widget Controller Class uninitialized,please fill out AuraHUD_BP"));
	
	auto const Widget = CreateWidget<UUserWidget>(GetWorld(),OverlayWidgetClass);
	OverlayWidget =  Cast<UAuraUserWidget>(Widget);

	const FWidgetControllerParams WidgetControllerParams(PC,PS,ASC,AS);
	const auto WidgetController = GetOverlayWidgetController(WidgetControllerParams);


	OverlayWidget->SetWidgetController(WidgetController);

	WidgetController->BroadcastInitValues();
	
	Widget->AddToViewport();
}
