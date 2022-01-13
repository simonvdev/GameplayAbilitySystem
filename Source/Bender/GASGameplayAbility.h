// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Bender.h"
#include "Abilities/GameplayAbility.h"
#include "GASGameplayAbility.generated.h"

/**
 * 
 */
UCLASS()
class BENDER_API UGASGameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()
	public:

	UPROPERTY(BlueprintReadOnly,EditAnywhere,Category = "Ability")
	EGASAbilityInputID AbilityInputID = EGASAbilityInputID::None;
	
};
