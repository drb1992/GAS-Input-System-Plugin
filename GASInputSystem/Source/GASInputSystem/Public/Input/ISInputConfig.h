// Copyright (c) 2023 intrxx. Original code from Enhanced Input Ability Activation, used under the MIT License.
// Copyright (c) 2026 Daniel Beaty. Modified for the GAS Input System plugin. See LICENSE.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "ISInputConfig.generated.h"

class UInputAction;
/**
 * FISInputAction
 *
 *	Struct used to map an input action to a gameplay input tag.
 */
USTRUCT(BlueprintType)
struct FISInputAction
{
	GENERATED_BODY()
public:
	UPROPERTY(EditDefaultsOnly)
	const UInputAction* InputAction = nullptr;

	UPROPERTY(EditDefaultsOnly, Meta = (Categories = "InputTag"))
	FGameplayTag InputTag;
};

/**
 * 
 */
UCLASS()
class GASINPUTSYSTEM_API UISInputConfig : public UDataAsset
{
	GENERATED_BODY()

public:
	// Returns the first Native Input Action associated with a given tag.
	const UInputAction* FindNativeInputActionForTag(const FGameplayTag& InputTag) const;
	// Returns the first Ability Input Action associated with a given tag.
	const UInputAction* FindAbilityInputActionForTag(const FGameplayTag& InputTag) const;

public:
	// List of input actions used by the owner. These input actions are mapped to a gameplay tag and must be manually bound.
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Meta = (TitleProperty = "InputAction"))
	TArray<FISInputAction> NativeInputActions;

	// List of input actions used to trigger abilities. These are mapped to a gameplay tag and bound automatically by BindAbilityActions.
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Meta = (TitleProperty = "InputAction"))
	TArray<FISInputAction> AbilityInputActions;
};
