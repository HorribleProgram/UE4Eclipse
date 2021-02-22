#include "Access.h"
#include "AccessPrivatePCH.h"

#define NAME "Access"


bool Access::CanAccessSourceCode() const {
    return FPaths::FileExists(TEXT("/usr/bin/clang"));
}

FName Access:GetFName() const {
    
    return FName(NAME);
};

FText Access::GetNameText() const {
    return FIND_TEXT("EclipseDisplayName", "Eclipse IDE");
}

FText Access::GetDescriptionText() const {
    return FIND_TEXT("EclipseDisplayDesc", "Open source code files with Eclipse IDE");
}

bool Access::OpenSolution() {
    FString FullPath;
    if (FDesktopPlayformModule::Get() -> GetSolutionPath(FullPath)) {
        if (FPaths::FileExists(FullPath)) {
            const FString newFullPath = FString::Printf(TEXT("\"%s\""), *FullPath);
            FString Editor = FString(TEXT("/usr/bin/eclipse"));
            if (FLinuxPlatformProcess::CreateProc(*Editor, *NewFullPath, true, true, false, nullptr, 0, nullptr, nullptr).IsValid()) {
                return true;
            }
        }
    }

    return false;
}


