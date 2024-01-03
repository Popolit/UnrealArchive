#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "NavigationComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ARCHIVE_API UNavigationComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	void ShowNavigation();

		
};
