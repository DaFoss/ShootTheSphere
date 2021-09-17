// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class ShootTheSphere : ModuleRules
{
	public ShootTheSphere(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { 
			"Core", 
			"CoreUObject", 
			"Engine", 
			"InputCore", 
			"HeadMountedDisplay", 
			"Niagara" 
		});

		PublicIncludePaths.AddRange(new string[] { 
			"ShootTheSphere/Public/ShootedActors",
			"ShootTheSphere/Public/UI"
		});
	}
}
