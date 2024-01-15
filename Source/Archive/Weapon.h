#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Weapon.generated.h"

UCLASS()
class ARCHIVE_API AWeapon : public AActor
{
	GENERATED_BODY()
public:
	AWeapon();
	void DoAction();
	void DoSubAction();


protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(VisibleInstanceOnly)
		TObjectPtr<USkeletalMeshComponent> Mesh_;

	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<class UAction> ActionClass_;
	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<class UAction> SubActionClass_;

	TScriptInterface<class IIAction> Action_;
	TScriptInterface<class IIAction> SubAction_;
};
