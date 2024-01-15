#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Projectile.generated.h"

UCLASS(Abstract)
class ARCHIVE_API AProjectile : public AActor
{
	GENERATED_BODY()
public:
	AProjectile();
	void Shot(const FVector& _Direction) const;

	virtual void Tick(float DeltaSeconds) override;
private:
	UFUNCTION()
		void OnBeginOverlap(UPrimitiveComponent* _OverlappedComponent, AActor* _OtherActor, UPrimitiveComponent* _OtherComp, int32 _OtherBodyIndex, bool _bFromSweep, const FHitResult& _SweepResult);
private:
	UPROPERTY(VisibleAnywhere)
		TObjectPtr<class UArrowComponent> Arrow_;
	UPROPERTY(VisibleDefaultsOnly)
		TObjectPtr<UStaticMeshComponent> Mesh_;
	UPROPERTY(VisibleDefaultsOnly)
		TObjectPtr<class UProjectileMovementComponent> PMComponent_;
	UPROPERTY(VisibleDefaultsOnly)
		TObjectPtr<class USphereComponent> CollisionComponent_;
};
