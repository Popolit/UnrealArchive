#include "NavigationSubsystem.h"

#include "EngineUtils.h"
#include "NavigationActor.h"
#include "ObjectiveActor.h"

void UNavigationSubsystem::OnWorldBeginPlay(UWorld& _InWorld)
{
	TActorIterator<ANavigationActor> It(&_InWorld);

	if(It)
	{
		NavActor_ = *It;
	}
}


void UNavigationSubsystem::ShowNavigation(const FVector& _From)
{
	if(NavActor_.IsNull())
	{
		return;
	}

	//Objective를 야매로 설정한 상태, 실제로는 더 깔끔하게 Objective 지점을 가져와야함
	//RPG면 다음 퀘스트 NPC의 위치, 콘솔이면 다음 지역 위치 등
	TActorIterator<AObjectiveActor> It(GetWorld());
	FVector To = It->GetActorLocation();
	To.Z = 0;
	if(It)
	{
		NavActor_->NavigateFromTo(FVector(_From.X, _From.Y, 0), To);
	}
}
