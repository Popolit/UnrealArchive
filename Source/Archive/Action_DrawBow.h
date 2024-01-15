#pragma once

#include "CoreMinimal.h"
#include "Action.h"
#include "Action_DrawBow.generated.h"

UCLASS()
class ARCHIVE_API UAction_DrawBow : public UAction
{
	GENERATED_BODY()

public:
	virtual void DoAction() override;

private:
	void Zoom(const ACharacter* _PlayerCharacter) const;
};
