// Fill out your copyright notice in the Description page of Project Settings.


#include "ArmouredFoe.h"
#include "ArmouredHealth.h"

/// <summary>
/// notice how the constructors super works differently
/// </summary>
AArmouredFoe::AArmouredFoe() : Super()
{

	//ArmouredHealth = CreateDefaultSubobject<UArmouredHealth>(TEXT("Armoured Health"));
}

void AArmouredFoe::BeginPlay()
{
	Super::BeginPlay();
	// cast health to armour healht
	if (ArmouredHealth)
	{
		// this attaches the healths died to the ondeath
		Health = dynamic_cast<UArmouredHealth>(Health);
		Health->ArmourBroken.AddDynamic(this, &AArmouredFoe::ArmourBroken);
	}
	else {
		UE_LOG(LogTemp, Error, TEXT("Armoured Health component is NULL in BeginPlay"));
	}
	
}

void AArmouredFoe::ArmourBroken() {
	// Function Definition
	//Change the material of the object}
	UE_LOG(LogTemp, Warning, TEXT("Armour Broken"));
	if (UnArmouredMaterial) {
		Body->SetMaterial(0, UnArmouredMaterial);
	}
}