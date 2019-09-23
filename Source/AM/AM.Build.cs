// AM.Build.cs

using UnrealBuildTool;

public class AM : ModuleRules
{
    public AM(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[] {
            "Core",
            "CoreUObject",
            "Engine",
            });
        
        PublicIncludePaths.AddRange(
            new string[]
            {
                "AM/Public"
            });

        PrivateIncludePaths.AddRange(
           new string[]
           {
                "AM/Private"
           });
    }
}