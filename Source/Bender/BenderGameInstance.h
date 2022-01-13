// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AdvancedFriendsGameInstance.h"
#include "BenderGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class BENDER_API UBenderGameInstance : public UAdvancedFriendsGameInstance
{
public:
	virtual void Init() override;
private:
	GENERATED_BODY()
};
