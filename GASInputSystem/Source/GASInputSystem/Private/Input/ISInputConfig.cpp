// Copyright (c) 2023 intrxx. Original code from Enhanced Input Ability Activation, used under the MIT License.
// Copyright (c) 2026 Daniel Beaty. Modified for the GAS Input System plugin. See LICENSE.


#include "Input/ISInputConfig.h"

const UInputAction* UISInputConfig::FindNativeInputActionForTag(const FGameplayTag& InputTag) const
{
	for (const FISInputAction& Action : NativeInputActions)
	{
		if (Action.InputAction && (Action.InputTag == InputTag))
		{
			return Action.InputAction;
		}
	}
	UE_LOG(LogTemp, Error, TEXT("UISInputConfig::FindNativeInputActionForTag: Can't find NativeInputAction for InputTag [%s] on InputConfig [%s]."), *InputTag.ToString(), *GetNameSafe(this));
	
	return nullptr;
}

const UInputAction* UISInputConfig::FindAbilityInputActionForTag(const FGameplayTag& InputTag) const
{
	for (const FISInputAction& Action : AbilityInputActions)
	{
		if (Action.InputAction && (Action.InputTag == InputTag))
		{
			return Action.InputAction;
		}
	}
	UE_LOG(LogTemp, Error, TEXT("UISInputConfig::FindAbilityInputActionForTag: Can't find AbilityInputAction for InputTag [%s] on InputConfig [%s]."), *InputTag.ToString(), *GetNameSafe(this));
	
	return nullptr;
}
