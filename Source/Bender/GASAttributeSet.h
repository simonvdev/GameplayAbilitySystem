// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "GASAttributeSet.generated.h"

/**
 * 
 */
 
 // Use macro form AttributeSet class
#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)
 
UCLASS()
class BENDER_API UGASAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

	public:
	
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	UPROPERTY(BlueprintReadOnly,Category = "Attributes", ReplicatedUsing = OnRep_Health)
	FGameplayAttributeData Health;
	
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, Health);

	UFUNCTION()
	virtual void OnRep_Health(const FGameplayAttributeData& oldHealth);


	
	UPROPERTY(BlueprintReadOnly,Category = "Attributes", ReplicatedUsing = OnRep_Stamina)
	FGameplayAttributeData Stamina;
	
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, Stamina);

	UPROPERTY(BlueprintReadOnly,Category = "Attributes",ReplicatedUsing = OnRep_Knockback)
	FGameplayAttributeData Knockback;

	ATTRIBUTE_ACCESSORS(UGASAttributeSet,Knockback);

	UFUNCTION()
	virtual void OnRep_Stamina(const FGameplayAttributeData& oldStamina);

	UFUNCTION()
	virtual void OnRep_Knockback(const FGameplayAttributeData& oldKnockback);
};
