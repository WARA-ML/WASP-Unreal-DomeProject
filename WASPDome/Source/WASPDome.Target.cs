// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;

public class WASPDomeTarget : TargetRules
{
	public WASPDomeTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
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
			"WASPUIComponents", "WASPUIElements"
		});
	}
}