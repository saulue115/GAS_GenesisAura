// Copyright Saul Augusto Gasca Farrera

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "AbilitySystemComponent.h"
#include "AbilitySystemInterface.h"
#include "AttributeSet.h"
#include "AuraPlayerState.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTAURAGENESIS_API AAuraPlayerState : public APlayerState,public IAbilitySystemInterface
{
	GENERATED_BODY()

public:

	AAuraPlayerState();

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	UAttributeSet* GetAttributeSet() const {return AttributeSet;}


protected:	
	UPROPERTY()
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent; 
	

	UPROPERTY()
	TObjectPtr<UAttributeSet> AttributeSet; 	
	
};
