#include "WeaponComponent.h"

#include "Weapon.h"

void UWeaponComponent::BeginPlay()
{
	Super::BeginPlay();

	Equip();
}

TWeakObjectPtr<AWeapon> UWeaponComponent::GetWeapon() const
{
	return Weapon_;
}

void UWeaponComponent::DoAction()
{
	if(Weapon_.IsNull())
	{
		return;
	}

	Weapon_->DoAction();
}

void UWeaponComponent::SubAction()
{
	if (Weapon_.IsNull())
	{
		return;
	}

	Weapon_->DoSubAction();
}

void UWeaponComponent::Equip()
{
	Weapon_ = NewObject<AWeapon>(GetOwner(), WeaponClass_);
}
