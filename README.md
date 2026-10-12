# GAS Input System Plugin

This is an Unreal Engine plugin I use to trigger Gameplay Ability System (GAS) abilities from Enhanced Input using Gameplay Tags, the same way Lyra does it.

## Credit

This plugin is built on [Enhanced Input Ability Activation](https://github.com/intrxx/Enhanced-Input-Ability-Activation) by intrxx (Michał Ogiński). The design and most of the code are theirs, and I'm using it under the MIT License. If you want to learn how the system works, their README is a great walkthrough.

## What I changed

* Turned the sample project into a standalone runtime plugin so I can drop it into any project.
* Kept only the reusable pieces: `UISAbilitySystemComponent`, `UISGameplayAbility`, `UISAbilitySet`, `UISInputComponent` and `UISInputConfig`.
* Removed the sample character, player controller, player state, game mode, asset manager, native gameplay tags and config files. Your project provides those now.
* Fixed the deprecation warning macros in `AbilitySpecInputPressed`. The original disabled them twice and never turned them back on.
* Fixed a possible crash in `AbilitySpecInputReleased` when an ability spec has no instances.
* Cleaned up dead code, log messages and module dependencies.

## Requirements

* Unreal Engine 5.5 or newer (I'm on 5.6)
* GameplayAbilities and EnhancedInput plugins

## Setup

1. Add `GASInputSystem` to your module's `Build.cs` dependencies.
2. In `DefaultInput.ini`, set `DefaultInputComponentClass=/Script/GASInputSystem.ISInputComponent`.
3. Use or subclass `UISAbilitySystemComponent` for your ASC and `UISGameplayAbility` for your abilities. Set the `ActivationPolicy` on each ability.
4. In your PlayerController's `PostProcessInput`, call `ASC->ProcessAbilityInput(DeltaTime, bGamePaused)` before calling `Super`.
5. In your pawn's `SetupPlayerInputComponent`, call `BindAbilityActions` and forward the pressed and released callbacks to `AbilityInputTagPressed` and `AbilityInputTagReleased`. Use `BindNativeAction` for things like move and look.
6. Create a `UISInputConfig` data asset that maps your Input Actions to tags, and a `UISAbilitySet` that maps your abilities to those same tags. Grant the set on the server with `GiveToAbilitySystem`.

The tag pickers only show tags under `InputTag`, so name your input tags like `InputTag.Jump`.

## License

MIT. The original work is copyright 2023 Michał Ogiński, and my changes are copyright 2026 Daniel Beaty. See `LICENSE`.
