// Copyright Saul Augusto Gasca Farrera

#pragma once

#include "CoreMinimal.h"
#include "../../Player/Characters/AuraCharacterBase.h"
#include "ProjectAuraGenesis/Intercation/EnemyInterface.h"
#include "AuraEnemy.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTAURAGENESIS_API AAuraEnemy : public AAuraCharacterBase,public IEnemyInterface
{
	GENERATED_BODY()

public:

	virtual void HighlightActor() override;

	virtual void UnHighlightActor() override;	
	
};
