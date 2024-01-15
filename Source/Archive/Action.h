#pragma once

#include "CoreMinimal.h"
#include "IAction.h"
#include "Action.generated.h"

UCLASS(Abstract)
class ARCHIVE_API UAction : public UObject, public IIAction
{
	GENERATED_BODY()

private:
	virtual void DoAction() override {}
};
