// Copyright Saul Augusto Gasca Farrera


#include "AuraPlayerController.h"

#include "ProjectAuraGenesis/Intercation/EnemyInterface.h"


AAuraPlayerController::AAuraPlayerController()
{
	bReplicates = true;
}

void AAuraPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);

	CursorTrace();
}

void AAuraPlayerController::CursorTrace()
{
	FHitResult Cursor;
	GetHitResultUnderCursor(ECC_Visibility,false,Cursor);

	if(!Cursor.bBlockingHit) return;

	LastActor = ThisActor;
	ThisActor = Cast<IEnemyInterface>(Cursor.GetActor());

	//Line Trace from cursor.There are several scenarios
	//if --> Last Actor is null && This actor is null -  do nothing
	//if --> Last Actor is null && This actor is validate -  highlight this actor
	//if --> Last Actor is valid && This actor is null -  unhighlight last actor
	//if --> Both Actors are valid, but last actor != this actor - unhighlight last actor and highlight this actor
	//if --> Both actor are valid, and are the same actors -  Do nothing

	if(LastActor == nullptr)
	{
		if(ThisActor != nullptr)
		{
			//Case B
			ThisActor->HighlightActor();
		}else
		{
			//Case A - both are null,do nothing
			
		}
	}else //last actor is valid
	{
		if(ThisActor == nullptr)
		{
			//Case C
			LastActor->UnHighlightActor();
		}
		else
		{
			if(LastActor != ThisActor)
			{
				//Case D
				LastActor->UnHighlightActor();
				ThisActor->HighlightActor();
			}else
			{
				//Case E -- do nothing
				
			}
		}
	}
	
}

void AAuraPlayerController::BeginPlay()
{
	Super::BeginPlay();

	check(AuraContext);

	UEnhancedInputLocalPlayerSubsystem*  Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());

	if(Subsystem)
	{
		Subsystem->AddMappingContext(AuraContext,0);
	}
	
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;

	FInputModeGameAndUI InputModeData;
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	InputModeData.SetHideCursorDuringCapture(false);
	SetInputMode(InputModeData);
}

void AAuraPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();


	UEnhancedInputComponent*  EnhancedInputComponent =  CastChecked<UEnhancedInputComponent>(InputComponent);

	EnhancedInputComponent->BindAction(MoveAction,ETriggerEvent::Triggered,this,&AAuraPlayerController::Move);
}

void AAuraPlayerController::Move(const FInputActionValue& InputActionValue)
{
	const FVector2D InputAxisVector = InputActionValue.Get<FVector2D>();

	const FRotator Rotation =  GetControlRotation();

	const FRotator YawRotation(0.0f,Rotation.Yaw,0.0f);

	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	if(APawn* ControlPawn  = GetPawn<APawn>())
	{
		ControlPawn->AddMovementInput(ForwardDirection,InputAxisVector.Y);
		ControlPawn->AddMovementInput(RightDirection,InputAxisVector.X);
	}
}
