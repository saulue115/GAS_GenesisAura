// Copyright Saul Augusto Gasca Farrera

using UnrealBuildTool;
using System.Collections.Generic;

public class ProjectAuraGenesisTarget : TargetRules
{
	public ProjectAuraGenesisTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V2;

		ExtraModuleNames.AddRange( new string[] { "ProjectAuraGenesis" } );
	}
}
