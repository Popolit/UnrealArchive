#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "NavigationSubsystem.generated.h"

/**
 * 
 */
UCLASS()
class ARCHIVE_API UNavigationSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	virtual void OnWorldBeginPlay(UWorld& _InWorld) override;
	void ShowNavigation(const FVector& _From);

private:
	TObjectPtr<class ANavigationActor> NavActor_;
};
