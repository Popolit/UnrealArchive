#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Enemy.generated.h"

UCLASS()
class ARCHIVE_API AEnemy : public ACharacter
{
	GENERATED_BODY()

public:
	AEnemy();

private:
	UPROPERTY(VisibleDefaultsOnly)
	TObjectPtr<class UWeaponComponent> WeaponComponent_;
};
