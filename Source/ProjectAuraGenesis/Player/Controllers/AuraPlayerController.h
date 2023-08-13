// Copyright Saul Augusto Gasca Farrera

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "../../Intercation/EnemyInterface.h"
#include "InputMappingContext.h"

#include "AuraPlayerController.generated.h"

struct FInputActionValue;

UCLASS()
class PROJECTAURAGENESIS_API AAuraPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	AAuraPlayerController();
	
	virtual void PlayerTick(float DeltaTime) override;

	void CursorTrace();
	
protected:
	virtual void BeginPlay() override;
	
	virtual void SetupInputComponent() override;
	
private:

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category=Input,meta=(AllowPrivateAccess=true))
	TObjectPtr<UInputMappingContext> AuraContext;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category=Input,meta=(AllowPrivateAccess=true))
	TObjectPtr<UInputAction> MoveAction = nullptr;


	void Move(const FInputActionValue& InputActionValue);

	IEnemyInterface* LastActor;
	IEnemyInterface* ThisActor;
	
};
