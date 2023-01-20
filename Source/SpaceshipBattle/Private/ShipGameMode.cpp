// Fill out your copyright notice in the Description page of Project Settings.


#include "ShipGameMode.h"
#include "SpaceShip.h"

AShipGameMode::AShipGameMode()
{
	DefaultPawnClass = ASpaceShip::StaticClass();
}

void AShipGameMode::IncreaseScore()
{
	Score++;
}

int AShipGameMode::GetScore()
{
	return Score;
}