// Copyright Saul Augusto Gasca Farrera

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "../Characters/AuraEnemy.h"
#include "GoblinAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTAURAGENESIS_API UGoblinAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:

	virtual void NativeInitializeAnimation();

	UFUNCTION(BlueprintCallable, Category=Animation)
	void BlueprintUpdateProperties(float DeltaTime);


	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category=Animation)
	float GroundSpeed = 0.0f;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category=Animation)
	FVector Velocity;

	
	
	AAuraEnemy* EnemyCharacter  = nullptr;	
};
