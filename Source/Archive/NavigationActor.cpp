#include "NavigationActor.h"

#include "Components/SplineComponent.h"
#include "Components/SplineMeshComponent.h"

ANavigationActor::ANavigationActor()
{
	Root_ = CreateDefaultSubobject<USceneComponent>("Root");
	SetRootComponent(Root_);

	Spline_ = CreateDefaultSubobject<USplineComponent>("Spline");
	Spline_->SetupAttachment(Root_);

	PrimaryActorTick.bCanEverTick = true;
}

//야매로 1초 이후 사라지도록 설정
void ANavigationActor::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	if(0 < TimeFromNavShow)
	{
		TimeFromNavShow -= DeltaSeconds;

		if(TimeFromNavShow <= 0)
		{
			//원래 이렇게 정리하면 안됨
			ClearInstanceComponents(true);
		}
	}
}

void ANavigationActor::NavigateFromTo(const FVector& _From, const FVector& _To)
{
	TimeFromNavShow = 3;

	const FVector BeginLocation = Spline_->FindLocationClosestToWorldLocation(_From, ESplineCoordinateSpace::World);
	const FVector EndLocation = Spline_->FindLocationClosestToWorldLocation(_To, ESplineCoordinateSpace::World);
	const FVector BeginTangent = BeginLocation - _From;
	const FVector EndTangent = _To - EndLocation;

	MakeSplineMeshComponent(_From, BeginTangent, BeginLocation, BeginTangent);
	MakeSplineMeshComponent(EndLocation, EndTangent, _To, EndTangent);

	const float BeginInputKey = Spline_->FindInputKeyClosestToWorldLocation(BeginLocation);
	const float EndInputKey = Spline_->FindInputKeyClosestToWorldLocation(EndLocation);

	//1 : 정방향, 0 : 역방향
	const bool Direction = BeginInputKey < EndInputKey;
	
	const uint32 FirstPoint = static_cast<uint32>(BeginInputKey) + Direction;
	const uint32 LastPoint = static_cast<int32>(EndInputKey) + !Direction;

	FVector Location, Tangent;
	Spline_->GetLocationAndTangentAtSplinePoint(FirstPoint, Location, Tangent, ESplineCoordinateSpace::World);
	MakeSplineMeshComponent(BeginLocation, Spline_->GetTangentAtSplineInputKey(BeginInputKey, ESplineCoordinateSpace::World), Location, Tangent);

	const int32 Coef = Direction ? 1 : -1;
	uint32 u = FirstPoint;
	while(u != LastPoint)
	{
		u += Coef;
		const FVector PrevLocation = Location;
		const FVector PrevTangent = Tangent;
		Spline_->GetLocationAndTangentAtSplinePoint(u, Location, Tangent, ESplineCoordinateSpace::World);

		MakeSplineMeshComponent(PrevLocation, PrevTangent, Location, Tangent);
	}
		

	Spline_->GetLocationAndTangentAtSplinePoint(LastPoint, Location, Tangent, ESplineCoordinateSpace::World);
	MakeSplineMeshComponent(Location, Tangent, EndLocation, Spline_->GetTangentAtSplinePoint(EndInputKey, ESplineCoordinateSpace::World));
}


void ANavigationActor::MakeSplineMeshComponent(const FVector& _From, const FVector& _FromTangent, const FVector& _To, const FVector& _ToTangent)
{
	USplineMeshComponent* NewSplineMesh = NewObject<USplineMeshComponent>(this);
	NewSplineMesh->SetupAttachment(Root_);
	NewSplineMesh->RegisterComponent();

	NewSplineMesh->SetMobility(EComponentMobility::Movable);
	NewSplineMesh->SetStaticMesh(Mesh_.LoadSynchronous());
	NewSplineMesh->SetStartAndEnd(_From, _FromTangent, _To, _ToTangent);
	AddInstanceComponent(NewSplineMesh);
}
