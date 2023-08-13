// Copyright Saul Augusto Gasca Farrera

#pragma once

#include "CoreMinimal.h"
#include "../../Player/Characters/AuraCharacterBase.h"
#include "ProjectAuraGenesis/Intercation/EnemyInterface.h"
#include "DrawDebugHelpers.h"
#include "AuraEnemy.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTAURAGENESIS_API AAuraEnemy : public AAuraCharacterBase,public IEnemyInterface
{
	GENERATED_BODY()

public:

	AAuraEnemy();

	virtual void HighlightActor() override;

	virtual void UnHighlightActor() override;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category=Interface)
	uint8 bHighlighted : 1; 



protected:
	
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;	
};
