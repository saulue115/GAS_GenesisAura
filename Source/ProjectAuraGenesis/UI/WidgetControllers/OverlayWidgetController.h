// Copyright Saul Augusto Gasca Farrera

#pragma once

#include "CoreMinimal.h"
#include "AuraWidgetController.h"
#include "OverlayWidgetController.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHealthChangedSignature,float, NewHealth);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMaxHealthChangedSignature,float, NewMaxHealth);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnManaChangedSignature, float, NewMana);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMaxManaChangedSignature, float, NewMaxMana);

UCLASS(BlueprintType,Blueprintable)
class PROJECTAURAGENESIS_API UOverlayWidgetController : public UAuraWidgetController
{
	GENERATED_BODY()

public:

	virtual void BroadcastInitValues() override;

	UPROPERTY(EditAnywhere,BlueprintAssignable,Category="Gas|Attributes")
	FOnHealthChangedSignature OnHealthChanged;


	UPROPERTY(EditAnywhere,BlueprintAssignable,Category="Gas|Attributes")
	FOnMaxHealthChangedSignature OnMaxHealthChanged;


	UPROPERTY(EditAnywhere,BlueprintAssignable,Category="Gas|Attributes")
	FOnManaChangedSignature OnManaChanged;


	UPROPERTY(EditAnywhere,BlueprintAssignable,Category="Gas|Attributes")
	FOnMaxManaChangedSignature OnMaxManaChanged;

	
	virtual void BindCallbacksToDependencies() override;


protected:

	void HealthChanged(const FOnAttributeChangeData& Data) const;

	void MaxHealthChanged(const FOnAttributeChangeData& Data) const;


	void ManaChanged(const FOnAttributeChangeData& Data) const;

	void MaxManaChanged(const FOnAttributeChangeData& Data) const;
};
