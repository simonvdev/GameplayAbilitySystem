// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Bender : ModuleRules
{
	public Bender(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "AdvancedSessions"});

		PrivateDependencyModuleNames.AddRange(new string[] { "GameplayAbilities", "GameplayTags","GameplayTasks","OnlineSubsystem" });

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });
		
		// Uncomment if you are using online features

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
