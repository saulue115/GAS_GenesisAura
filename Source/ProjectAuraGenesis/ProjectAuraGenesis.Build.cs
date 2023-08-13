// Copyright Saul Augusto Gasca Farrera

using UnrealBuildTool;

public class ProjectAuraGenesis : ModuleRules
{
	public ProjectAuraGenesis(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore","EnhancedInput","AIModule","NavigationSystem","GameplayTasks","GameplayAbilities","SlateCore","UMG" });

		PrivateDependencyModuleNames.AddRange(new string[] { "GameplayTags" });

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });
		
		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
