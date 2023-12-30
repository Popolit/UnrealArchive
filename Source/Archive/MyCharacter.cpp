#include "MyCharacter.h"

#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"

AMyCharacter::AMyCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	SpringArmComponent_ = CreateDefaultSubobject<USpringArmComponent>("SpringArm");
	CameraComponent_ = CreateDefaultSubobject<UCameraComponent>("Camera");

	SpringArmComponent_->SetRelativeLocation(FVector(0.0, 0.0, 150.0));
	SpringArmComponent_->SetRelativeRotation(FRotator(0.0, 90.0, 0.0));

	SpringArmComponent_->SetupAttachment(GetMesh());
	CameraComponent_->SetupAttachment(SpringArmComponent_);

	

	//true�� ���, �ٶ󺸴� ����� ī�޶� ����ȭ
	bUseControllerRotationYaw = false;

	//���������� �� ��Ʈ�� �����̼��� ����, ��Ȱ��ȭ�� ī�޶� �ȿ�����
	SpringArmComponent_->bUsePawnControlRotation = true;
	GetCharacterMovement()->bOrientRotationToMovement = true;
}

void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveF", this, &AMyCharacter::MoveF);
	PlayerInputComponent->BindAxis("MoveR", this, &AMyCharacter::MoveR);
	PlayerInputComponent->BindAxis("LookUp", this, &AMyCharacter::LookUp);
	PlayerInputComponent->BindAxis("LookRight", this, &AMyCharacter::LookRIght);
}

void AMyCharacter::MoveF(float _Amount)
{
	FVector Direction = FVector(_Amount, 0.0f, 0.0f);

	const FRotator CharacterRotation = GetControlRotation();
	Direction = CharacterRotation.RotateVector(Direction);

	AddMovementInput(Direction.GetSafeNormal2D());
}

void AMyCharacter::MoveR(float _Amount)
{
	FVector Direction = FVector(0.0f, _Amount, 0.0f);

	const FRotator CharacterRotation = GetControlRotation();
	Direction = CharacterRotation.RotateVector(Direction);

	AddMovementInput(Direction.GetSafeNormal2D());
}

void AMyCharacter::LookUp(float _Amount)
{
	AddControllerPitchInput(_Amount);
}

void AMyCharacter::LookRIght(float _Amount)
{
	AddControllerYawInput(_Amount);
}

