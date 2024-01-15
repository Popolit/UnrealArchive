#pragma once

#include "CoreMinimal.h"
#include "Action.h"
#include "Action_ShotProjectile.generated.h"

UCLASS()
class ARCHIVE_API UAction_ShotProjectile : public UAction
{
	GENERATED_BODY()

public:
	virtual void DoAction() override;

private:
	UPROPERTY(EditDefaultsOnly)
		TSoftObjectPtr<class UAnimationAsset> AnimAsset_;
};
