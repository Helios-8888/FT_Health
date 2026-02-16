// Fill out your copyright notice in the Description page of Project Settings.

#include <cmath>
#include "ArmouredHealth.h"

/**
* Here is the CPP file where we will put our logic
* A slight hint to help you is 
* UHealth::Damage will call the base class (UHealths) damage funtion not the Armoured Health Damage
* 
*/


UArmouredHealth::UArmouredHealth() {
	Super::UHealth();
	RemainingArmour = MaxArmour;

}

void UArmouredHealth::TakeDamage(int Damage)
{
	int reducedDamage = 0;
	if (RemainingArmour > 0) {

		if (Damage < LowDamageThreshold) {
			reducedDamage = std::max((Damage / DamageType1Reduction), 1); //Set it to reduce damage by half
		}
		else {
			reducedDamage = Damage - DamageType2Reduction;
		}
		if (reducedDamage > RemainingArmour) {
			ArmourBroken.Broadcast();
		}
	}

	UE_LOG(LogTemp, Warning, TEXT("Armoured Health reduced damage to %d"), reducedDamage);
	
	RemainingArmour -= reducedDamage;
	if (RemainingArmour <= 0) {
		Super::TakeDamage(-RemainingArmour);
		RemainingArmour = 0;
	}

}

