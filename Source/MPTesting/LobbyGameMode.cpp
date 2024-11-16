// Fill out your copyright notice in the Description page of Project Settings.


#include "LobbyGameMode.h"

#include "GameFramework/GameStateBase.h"
#include "GameFramework/PlayerState.h"

void ALobbyGameMode::PostLogin(APlayerController* NewPlayer)
{
	Super::PostLogin(NewPlayer);
	if(GameState)
	{
		int32 NumOfPlayers = GameState.Get()->PlayerArray.Num();
		if(GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, FString::Printf(TEXT("Num of players: %d"), NumOfPlayers));
		}

		APlayerState* PlayerState = NewPlayer->GetPlayerState<APlayerState>();
		if(PlayerState)
		{
			FString PlayerName = PlayerState->GetPlayerName();
			if(GEngine)
			{
				GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Cyan, FString::Printf(TEXT("%s joined game"), *PlayerName));
			}
		}
	}
}

void ALobbyGameMode::Logout(AController* Exiting)
{
	Super::Logout(Exiting);
	if(GameState)
	{
		int32 NumOfPlayers = GameState.Get()->PlayerArray.Num();
		if(GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, FString::Printf(TEXT("Num of players: %d"), NumOfPlayers-1));
		}

		APlayerState* PlayerState = Exiting->GetPlayerState<APlayerState>();
		if(PlayerState)
		{
			FString PlayerName = PlayerState->GetPlayerName();
			if(GEngine)
			{
				GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Cyan, FString::Printf(TEXT("%s exited game"), *PlayerName));
			}
		}
	}
}
