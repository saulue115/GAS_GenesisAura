// Copyright Saul Augusto Gasca Farrera

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "../Characters/AuraCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "AuraAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTAURAGENESIS_API UAuraAnimInstance : public UAnimInstance
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

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category=Animation)
	uint8 bShouldMove : 1;
	
	
	AAuraCharacter* AuraCharacter  = nullptr;
	
};
