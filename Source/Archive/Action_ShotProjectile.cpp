#include "Action_ShotProjectile.h"


void UAction_ShotProjectile::DoAction()
{
	AActor* Actor = Cast<AActor>(GetOuter());
	if(nullptr == Actor)
	{
		return;
	}

}
