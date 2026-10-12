// Copyright (c) 2023 intrxx. Original code from Enhanced Input Ability Activation, used under the MIT License.
// Copyright (c) 2026 Daniel Beaty. Modified for the GAS Input System plugin. See LICENSE.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "ISAbilitySystemComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class GASINPUTSYSTEM_API UISAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()

public:
	UISAbilitySystemComponent();

	void AbilityInputTagPressed(const FGameplayTag& InputTag);
	void AbilityInputTagReleased(const FGameplayTag& InputTag);

	void ProcessAbilityInput(float DeltaTime, bool bGamePaused);
	void ClearAbilityInput();

protected:
	virtual void AbilitySpecInputPressed(FGameplayAbilitySpec& Spec) override;
	virtual void AbilitySpecInputReleased(FGameplayAbilitySpec& Spec) override;

protected:
	// Handles to abilities that had their input pressed this frame.
	TArray<FGameplayAbilitySpecHandle> InputPressedSpecHandles;

	// Handles to abilities that had their input released this frame.
	TArray<FGameplayAbilitySpecHandle> InputReleasedSpecHandles;

	// Handles to abilities that have their input held.
	TArray<FGameplayAbilitySpecHandle> InputHeldSpecHandles;
};
