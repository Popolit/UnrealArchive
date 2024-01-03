#include "NavigationComponent.h"

void UNavigationComponent::ShowNavigation()
{
	AActor* Owner = GetOwner();
	if(nullptr == Owner)
	{
		return;
	}

	Owner->GetActorLocation();
}
