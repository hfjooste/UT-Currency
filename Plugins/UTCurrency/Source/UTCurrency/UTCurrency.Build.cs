using UnrealBuildTool;

public class UTCurrency : ModuleRules
{
	public UTCurrency(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		PublicIncludePaths.AddRange(new string[] { });
		PrivateIncludePaths.AddRange(new string[] { });
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "UTLogger" });
		PrivateDependencyModuleNames.AddRange(new string[] { "CoreUObject", "Engine", "Slate", "SlateCore", "UTLogger" });
		DynamicallyLoadedModuleNames.AddRange(new string[] { });
	}
}
