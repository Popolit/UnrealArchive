#include "Action_DrawBow.h"

#include "WeaponComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/Character.h"

void UAction_DrawBow::DoAction()
{
	const ACharacter* Owner = Cast<ACharacter>(GetOuter());

	if(nullptr == Owner)
	{
		return;
	}

	auto WeaponComponent = Cast<UWeaponComponent>(Owner->GetComponentByClass(UWeaponComponent::StaticClass()));
	if(nullptr == WeaponComponent)
	{
		return;
	}

	TWeakObjectPtr<AWeapon> Weapon = WeaponComponent->GetWeapon();
	if(Weapon.IsExplicitlyNull() || Weapon.IsStale())
	{
		return;
	}

	if(Owner->IsPlayerControlled())
	{
		Zoom(Owner);
	}

}

void UAction_DrawBow::Zoom(const ACharacter* _PlayerCharacter) const
{
	const auto Camera = Cast<UCameraComponent>(_PlayerCharacter->GetComponentByClass(UCameraComponent::StaticClass()));

	if(nullptr == Camera)
	{
		return;
	}
}
