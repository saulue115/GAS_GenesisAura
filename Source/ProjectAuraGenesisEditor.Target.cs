// Copyright Saul Augusto Gasca Farrera

using UnrealBuildTool;
using System.Collections.Generic;

public class ProjectAuraGenesisEditorTarget : TargetRules
{
	public ProjectAuraGenesisEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V2;

		ExtraModuleNames.AddRange( new string[] { "ProjectAuraGenesis" } );
	}
}
