// Copyright Saul Augusto Gasca Farrera


#include "GoblinAnimInstance.h"

void UGoblinAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	if(!EnemyCharacter)
	{
		EnemyCharacter = Cast<AAuraEnemy>(TryGetPawnOwner());
	}
}

void UGoblinAnimInstance::BlueprintUpdateProperties(float DeltaTime)
{
	EnemyCharacter = Cast<AAuraEnemy>(TryGetPawnOwner());

	if(!EnemyCharacter || !GetWorld()) return;

	Velocity = EnemyCharacter->GetVelocity();
	GroundSpeed = Velocity.Size();
}
