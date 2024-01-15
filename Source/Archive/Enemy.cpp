#include "Enemy.h"

#include "WeaponComponent.h"

AEnemy::AEnemy()
{
	WeaponComponent_ = CreateDefaultSubobject<UWeaponComponent>("Weapon");
}
