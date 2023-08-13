// Copyright Saul Augusto Gasca Farrera

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "AbilitySystemComponent.h"
#include "AbilitySystemInterface.h"
#include "ProjectAuraGenesis/AbilitySystem/AuraAttributeSet.h"
#include "AuraEffectActor.generated.h"

UCLASS()
class PROJECTAURAGENESIS_API AAuraEffectActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAuraEffectActor();

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category=Components)
	TObjectPtr<USphereComponent> SphereComponent  = nullptr;


	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category=Components)
	TObjectPtr<UStaticMeshComponent> MeshComponent  = nullptr;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


public:

	UFUNCTION()
	virtual void OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	virtual void EndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
	

};
