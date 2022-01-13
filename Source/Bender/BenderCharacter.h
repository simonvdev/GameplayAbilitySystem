// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/PBPlayerCharacter.h"
#include "AbilitySystemInterface.h"
#include <GameplayEffectTypes.h>
#include "BenderCharacter.generated.h"



UCLASS()
class BENDER_API ABenderCharacter : public APBPlayerCharacter , public IAbilitySystemInterface
{
public:
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;
private:
	GENERATED_BODY()

public:
	ABenderCharacter(const FObjectInitializer& ObjectInitializer);
	
	// Variables
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Abilities", meta = (AllowPrivateAcces = "true"))
	class UGASSystemComponent * AbilitySystemComponent;

	UPROPERTY()
	class UGASAttributeSet * Attributes;

	// Functions
	virtual class UAbilitySystemComponent * GetAbilitySystemComponent() const override;

	virtual void InitializeAttributes();
	virtual void GiveAbilities();

	

	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState() override;
	
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly,Category = "Abilities")
	TSubclassOf<class UGameplayEffect> DefaultAttributeEffect;

	UPROPERTY(BlueprintReadOnly,EditDefaultsOnly,Category = "Abilties")
	TArray<TSubclassOf<class UGASGameplayAbility>> DefaultAbilities;
	
};
