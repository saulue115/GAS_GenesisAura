// Copyright Saul Augusto Gasca Farrera

#pragma once

#include "CoreMinimal.h"
#include "AuraCharacterBase.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "AuraCharacter.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTAURAGENESIS_API AAuraCharacter : public AAuraCharacterBase
{
	GENERATED_BODY()

public:

	AAuraCharacter();

	virtual void PossessedBy(AController* NewController) override;

	virtual void OnRep_PlayerState() override;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category=Components)
	TObjectPtr<USpringArmComponent> BoomCamera = nullptr;


	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category=Components)
	TObjectPtr<UCameraComponent> FollowCamera = nullptr;

private:

	void InitAbilityActorInfo();
};
