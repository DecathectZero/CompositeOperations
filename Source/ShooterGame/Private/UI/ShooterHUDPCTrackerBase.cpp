// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "ShooterGame.h"
#include "ShooterHUDPCTrackerBase.h"


/** Initialize with a world context. */
void ShooterHUDPCTrackerBase::Init( const FLocalPlayerContext& InContext )
{
	Context = InContext;
}

TWeakObjectPtr<AShooterPlayerController> ShooterHUDPCTrackerBase::GetPlayerController() const
{
	if ( ensureMsgf( Context.IsValid(), TEXT("Game context must be initialized!") ) )
	{
		APlayerController* PC = Context.GetPlayerController();
		AShooterPlayerController* ShooterPC = Cast<AShooterPlayerController>(PC);
		return TWeakObjectPtr<AShooterPlayerController>(ShooterPC);
	}
	else
	{
		return NULL;
	}
}


UWorld* ShooterHUDPCTrackerBase::GetWorld() const
{
	if ( ensureMsgf( Context.IsValid(), TEXT("Game context must be initialized!") ) )
	{
		return Context.GetWorld();
	}
	else
	{
		return NULL;
	}
}

AShooterGameState* ShooterHUDPCTrackerBase::GetGameState() const
{
	if ( ensureMsgf( Context.IsValid(), TEXT("Game context must be initialized!") ) )
	{
		return Cast<AShooterGameState>(Context.GetWorld()->GameState);
	}
	else
	{
		return NULL;
	}
}

const FLocalPlayerContext& ShooterHUDPCTrackerBase::GetContext() const
{
	return Context;
}



