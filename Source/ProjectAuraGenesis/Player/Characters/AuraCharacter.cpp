// Copyright Saul Augusto Gasca Farrera


#include "AuraCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "ProjectAuraGenesis/Player/Controllers/AuraPlayerState.h"

AAuraCharacter::AAuraCharacter()
{
	BoomCamera = CreateDefaultSubobject<USpringArmComponent>(TEXT("Boom Camera"));
	BoomCamera->SetupAttachment(RootComponent);
	BoomCamera->TargetArmLength = 750.f;
	BoomCamera->bUsePawnControlRotation = false;
	BoomCamera->bEnableCameraLag = true;
	BoomCamera->bInheritPitch = false;
	BoomCamera->bInheritRoll = false;
	BoomCamera->bInheritYaw = false;


	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("Follow Camera"));
	FollowCamera->SetupAttachment(BoomCamera,USpringArmComponent::SocketName);
	FollowCamera->bUsePawnControlRotation = false;

	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.f, 400.f, 0.f);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;

	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationRoll = false;
}

void AAuraCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	//Init ability actor info for the server
	InitAbilityActorInfo();
}

void AAuraCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();

	//Init ability info for the client
	InitAbilityActorInfo();
}

void AAuraCharacter::InitAbilityActorInfo()
{
	
	AAuraPlayerState* AuraPlayerState = GetPlayerState<AAuraPlayerState>();

	if(!AuraPlayerState) return;

	AuraPlayerState->GetAbilitySystemComponent()->InitAbilityActorInfo(AuraPlayerState,this);

	AbilitySystemComponent = AuraPlayerState->GetAbilitySystemComponent();
	AttributeSet = AuraPlayerState->GetAttributeSet();
}
