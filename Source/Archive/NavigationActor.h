#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NavigationActor.generated.h"

UCLASS()
class ARCHIVE_API ANavigationActor : public AActor
{
	GENERATED_BODY()
	
public:	
	ANavigationActor();
	virtual void Tick(float DeltaSeconds) override;
	void NavigateFromTo(const FVector& _From, const FVector& _To);

private:
	void MakeSplineMeshComponent(const FVector& _From, const FVector& _FromTangent, const FVector& _To, const FVector& _ToTangent);

private:
	UPROPERTY(EditDefaultsOnly)
	TSoftObjectPtr<class UStaticMesh> Mesh_;
	UPROPERTY(EditInstanceOnly)
	TObjectPtr<class USplineComponent> Spline_;

	TObjectPtr<class USceneComponent> Root_;
	float TimeFromNavShow = 0;
};
