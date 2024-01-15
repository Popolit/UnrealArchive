#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "WeaponComponent.generated.h"

class AWeapon;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ARCHIVE_API UWeaponComponent : public UActorComponent
{
	GENERATED_BODY()
protected:
	virtual void BeginPlay() override;

public:
	TWeakObjectPtr<AWeapon> GetWeapon() const;
	void DoAction();
	void SubAction();

private:
	void Equip();

private:
	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<AWeapon> WeaponClass_;
	TObjectPtr<AWeapon> Weapon_;
};
