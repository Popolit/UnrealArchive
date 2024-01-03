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

	//Objective�� �߸ŷ� ������ ����, �����δ� �� ����ϰ� Objective ������ �����;���
	//RPG�� ���� ����Ʈ NPC�� ��ġ, �ܼ��̸� ���� ���� ��ġ ��
	TActorIterator<AObjectiveActor> It(GetWorld());
	FVector To = It->GetActorLocation();
	To.Z = 0;
	if(It)
	{
		NavActor_->NavigateFromTo(FVector(_From.X, _From.Y, 0), To);
	}
}
