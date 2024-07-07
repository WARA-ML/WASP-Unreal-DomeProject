// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;

public class WASPDomeEditorTarget : TargetRules
{
	public WASPDomeEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V2;

		ExtraModuleNames.AddRange(new[] { "WASPDome" });
		RegisterModulesCreatedByRider();
	}

	private void RegisterModulesCreatedByRider()
	{
		ExtraModuleNames.AddRange(new[]
		{
			"WASPDomeCore",
			"WASPUserInterface",
			"WASPUIComponents",
			"WASPUIElements"
		});
	}
}