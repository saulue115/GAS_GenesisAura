// Copyright Saul Augusto Gasca Farrera

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AuraCharacterBase.generated.h"

UCLASS(Abstract)
class PROJECTAURAGENESIS_API AAuraCharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AAuraCharacterBase();


	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category=Combat)
	TObjectPtr<USkeletalMeshComponent> Weapon = nullptr;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


	

};
