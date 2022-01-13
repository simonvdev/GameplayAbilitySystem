// Fill out your copyright notice in the Description page of Project Settings.


#include "BenderGameInstance.h"
#include "AbilitySystemGlobals.h"

void UBenderGameInstance::Init()
{
	Super::Init();

	UAbilitySystemGlobals::Get().InitGlobalData();
}
