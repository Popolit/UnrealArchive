#include "Weapon.h"

#include "Action.h"

AWeapon::AWeapon()
{
	Mesh_ = CreateDefaultSubobject<USkeletalMeshComponent>("Mesh");
	SetRootComponent(Mesh_);
}

void AWeapon::DoAction()
{
	if(Action_)
	{
		Action_->DoAction();
	}
}

void AWeapon::DoSubAction()
{
	if (SubAction_)
	{
		SubAction_->DoAction();
	}
}

void AWeapon::BeginPlay()
{
	Super::BeginPlay();

	if(ActionClass_)
	{
		Action_ = NewObject<UAction>(this, ActionClass_);
	}
	if(SubActionClass_)
	{
		SubAction_ = NewObject<UAction>(this, SubActionClass_);
	}
}
