// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "ISGameplayAbility.generated.h"

/**
 * Defines how ability is meant to activate
 */
UENUM(BlueprintType)
enum class EISAbilityActivationPolicy : uint8
{
	OnInputTriggered,
	WhileInputActive,
};

/**
 * 
 */
UCLASS()
class GASINPUTSYSTEM_API UISGameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	EISAbilityActivationPolicy GetActivationPolicy() const {return ActivationPolicy;}
	
protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "SN|Ability Activation")
	EISAbilityActivationPolicy ActivationPolicy;
};
