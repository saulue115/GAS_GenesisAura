// Copyright Saul Augusto Gasca Farrera


#include "AuraAnimInstance.h"

void UAuraAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	if(!AuraCharacter)
	{
		AuraCharacter = Cast<AAuraCharacter>(TryGetPawnOwner());
	}
	
}

void UAuraAnimInstance::BlueprintUpdateProperties(float DeltaTime)
{
	AuraCharacter = Cast<AAuraCharacter>(TryGetPawnOwner());

	if(!AuraCharacter || !GetWorld()) return;

	 Velocity = AuraCharacter->GetVelocity();
	GroundSpeed = Velocity.Size();
	
	GroundSpeed > 3.0f ? bShouldMove = true : bShouldMove = false;
}
