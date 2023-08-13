// Copyright Saul Augusto Gasca Farrera


#include "AuraEnemy.h"
#include "ProjectAuraGenesis/ProjectAuraGenesis.h"
#include "ProjectAuraGenesis/AbilitySystem/AuraAbilitySystemComponent.h"
#include "ProjectAuraGenesis/AbilitySystem/AuraAttributeSet.h"



AAuraEnemy::AAuraEnemy()
{

	GetMesh()->SetCollisionResponseToChannel(ECC_Visibility,ECR_Block);

	AbilitySystemComponent = CreateDefaultSubobject<UAuraAbilitySystemComponent>("Ability System Component");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);


	AttributeSet = CreateDefaultSubobject<UAuraAttributeSet>("Attribute Set");
}

void AAuraEnemy::BeginPlay()
{
	Super::BeginPlay();

	check(AbilitySystemComponent);

	AbilitySystemComponent->InitAbilityActorInfo(this,this);
}

void AAuraEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// if(bHighlighted)
	// {
	// 	DrawDebugSphere(GetWorld(),GetActorLocation(),50.0f,12,FColor::Orange);
	// }

	
}

void AAuraEnemy::HighlightActor()
{
	
	
	GetMesh()->SetRenderCustomDepth(true);
	GetMesh()->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED);
	Weapon->SetRenderCustomDepth(true);
	Weapon->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED);
}

void AAuraEnemy::UnHighlightActor()
{
	

	GetMesh()->SetRenderCustomDepth(false);
	Weapon->SetRenderCustomDepth(false);
}
