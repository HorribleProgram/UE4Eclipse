#pragma once

class Accessor: public ISourceCodeAccessor {
public:
    // superclass implementation
    virtual bool CanAccessSourceCode() const override;
    virtual FName GetFName() const override;
    virtual FText GetNameText() const override;
    virtual FText GetDescriptionText() const override;
    virtual bool OpenSolution() override;
    virtual bool OpenFileAtLine(const FString& FullPath, int32 LineNumbert, int32 ColumnNumber = 0) override;
    virtual bool OpenSourceFiles(const TArray<FString>& AbsoluteSourcePaths) override;
    virtual bool AddSourceFiles(const TArray<FString>& AbsoluteSourchPaths, const TArray<FString>& AvailableModules) override;
    virtual bool Tick(const float DeltaTime) override;
};
