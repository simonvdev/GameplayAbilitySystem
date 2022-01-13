// Fill out your copyright notice in the Description page of Project Settings.


#include "BenderCharacter.h"

#include "GASAttributeSet.h"
#include "GASGameplayAbility.h"
#include "GASSystemComponent.h"

void ABenderCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	check(PlayerInputComponent);

	if(AbilitySystemComponent && InputComponent)
	{
		const FGameplayAbilityInputBinds Binds("Confirm", "Cancel", "EGASAbilityInputID",
											static_cast<int32>(EGASAbilityInputID::Confirm),
											static_cast<int32>(EGASAbilityInputID::Cancel));

		AbilitySystemComponent->BindAbilityActivationToInputComponent(InputComponent, Binds);
		
	}
}

ABenderCharacter::ABenderCharacter(const FObjectInitializer& ObjectInitializer)
	: APBPlayerCharacter(ObjectInitializer)
{
	AbilitySystemComponent = CreateDefaultSubobject<UGASSystemComponent>("AbilitySystem");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);

	Attributes =  CreateDefaultSubobject<UGASAttributeSet>("Attributes");
}

UAbilitySystemComponent* ABenderCharacter::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}



/**
 * @brief Initialize gameplay attributes with default values
 */
void ABenderCharacter::InitializeAttributes()
{
	if(AbilitySystemComponent && DefaultAttributeEffect)
	{
		FGameplayEffectContextHandle EffectContextHandle = AbilitySystemComponent->MakeEffectContext();
		EffectContextHandle.AddSourceObject(this);

		FGameplayEffectSpecHandle SpecHandle = AbilitySystemComponent->MakeOutgoingSpec(DefaultAttributeEffect,1,EffectContextHandle);
		if(SpecHandle.IsValid())
		{
			FActiveGameplayEffectHandle GFHandle = AbilitySystemComponent->ApplyGameplayEffectSpecToSelf(*SpecHandle.Data.Get());
		}
	}
}


/**
 * @brief  Gives the current character abilities should only be called on server
 */
void ABenderCharacter::GiveAbilities()
{
	if(HasAuthority() && AbilitySystemComponent)
	{
		for (TSubclassOf<UGASGameplayAbility> & Ability : DefaultAbilities)
		{
			AbilitySystemComponent->GiveAbility(FGameplayAbilitySpec(Ability, 1, static_cast<int32>(Ability.GetDefaultObject()->AbilityInputID), this));
		}
	}
}

// Called on Server
void ABenderCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	AbilitySystemComponent->InitAbilityActorInfo(this,this);

	InitializeAttributes();
	GiveAbilities();
}

// Called on client
void ABenderCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();

	AbilitySystemComponent->InitAbilityActorInfo(this,this);

	InitializeAttributes();

	if(AbilitySystemComponent && InputComponent)
	{
		const FGameplayAbilityInputBinds Binds("Confirm", "Cancel", "EGASAbilityInputID",
		                                       static_cast<int32>(EGASAbilityInputID::Confirm),
		                                       static_cast<int32>(EGASAbilityInputID::Cancel));

		AbilitySystemComponent->BindAbilityActivationToInputComponent(InputComponent, Binds);
		
	}
}
