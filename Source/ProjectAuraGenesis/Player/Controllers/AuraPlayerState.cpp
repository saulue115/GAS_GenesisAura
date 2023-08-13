// Copyright Saul Augusto Gasca Farrera


#include "AuraPlayerState.h"
#include "ProjectAuraGenesis/AbilitySystem/AuraAbilitySystemComponent.h"
#include "ProjectAuraGenesis/AbilitySystem/AuraAttributeSet.h"

AAuraPlayerState::AAuraPlayerState()
{
	AbilitySystemComponent = CreateDefaultSubobject<UAuraAbilitySystemComponent>("Ability System Component");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);


	AttributeSet = CreateDefaultSubobject<UAuraAttributeSet>("Attribute Set");
	
	NetUpdateFrequency = 100.0f;
}

UAbilitySystemComponent* AAuraPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}
