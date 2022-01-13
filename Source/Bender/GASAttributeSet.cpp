// Fill out your copyright notice in the Description page of Project Settings.


#include "GASAttributeSet.h"

#include "Net/UnrealNetwork.h"

void UGASAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION_NOTIFY(UGASAttributeSet,Health,COND_None,REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UGASAttributeSet,Stamina,COND_None,REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UGASAttributeSet,Knockback,COND_None,REPNOTIFY_Always);
}

void UGASAttributeSet::OnRep_Health(const FGameplayAttributeData& oldHealth)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGASAttributeSet,Health,oldHealth);
}

void UGASAttributeSet::OnRep_Stamina(const FGameplayAttributeData& oldStamina)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGASAttributeSet,Stamina,oldStamina);
}

void UGASAttributeSet::OnRep_Knockback(const FGameplayAttributeData& oldKnockback)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGASAttributeSet,Knockback,oldKnockback);
}
