// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Health.h"
#include "ArmouredHealth.generated.h"

/**
 * here is the armoured health
 * You will need add some variables 
 * Give it a go
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FArmourBroken);

UCLASS()
class HEALTHDEMO_API UArmouredHealth : public UHealth
{
	GENERATED_BODY()
	
	public:
		UArmouredHealth();
		// notice i have to say this is an override
		void TakeDamage(int Damage) override;;
		UPROPERTY(VisibleAnywhere, Category = "Armour|MaxArmour")
		int MaxArmour = 100;
		UPROPERTY(VisibleAnywhere, Category = "Armour|Remaining Armour")
		int RemainingArmour;

		int DamageType1Reduction = 2;
		int DamageType2Reduction = 5;
		int LowDamageThreshold = 10;

		FArmourBroken ArmourBroken;
};
