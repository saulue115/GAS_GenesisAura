// Copyright Saul Augusto Gasca Farrera


#include "AuraGameModeBase.h"

AAuraGameModeBase::AAuraGameModeBase()
{
	
	DefaultPawnClass = AAuraCharacter::StaticClass();
	PlayerControllerClass = AAuraPlayerController::StaticClass();
}
