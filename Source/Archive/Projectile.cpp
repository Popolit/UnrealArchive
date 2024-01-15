#include "Projectile.h"

#include "Components/ArrowComponent.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"

AProjectile::AProjectile()
{
	PrimaryActorTick.bCanEverTick = true;
	Arrow_ = CreateDefaultSubobject<UArrowComponent>("Arrow");
	SetRootComponent(Arrow_);

	Mesh_ = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	Mesh_->SetupAttachment(Arrow_);

	PMComponent_ = CreateDefaultSubobject<UProjectileMovementComponent>("ProjectileMovement");

	CollisionComponent_ = CreateDefaultSubobject<USphereComponent>("Collision");
	CollisionComponent_->SetupAttachment(Mesh_);
	CollisionComponent_->OnComponentBeginOverlap.AddDynamic(this, &AProjectile::OnBeginOverlap);
}

void AProjectile::Shot(const FVector& _Direction) const
{
	PMComponent_->SetVelocityInLocalSpace(_Direction * PMComponent_->InitialSpeed);
}

void AProjectile::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	for(auto& Elem : GetInstanceComponents())
	{
		GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Black, Elem->GetName(), true);
	}
}

void AProjectile::OnBeginOverlap(UPrimitiveComponent* _OverlappedComponent, AActor* _OtherActor,
                                 UPrimitiveComponent* _OtherComp, int32 _OtherBodyIndex, bool _bFromSweep, const FHitResult& _SweepResult)
{
	PMComponent_->SetVelocityInLocalSpace(FVector::ZeroVector);

	/* Other Actor -> Hit Process */
	/* Other Actor -> Damage Process */
}

