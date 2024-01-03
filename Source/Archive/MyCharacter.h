#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MyCharacter.generated.h"

UCLASS()
class ARCHIVE_API AMyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AMyCharacter();
	virtual void BeginPlay() override;
	virtual void SetupPlayerInputComponent(class UInputComponent* _PlayerInputComponent) override;

private:
	void MoveF(float _Amount);
	void MoveR(float _Amount);
	void LookUp(float _Amount);
	void LookRIght(float _Amount);

	void Navigation();

private:
	UPROPERTY()
	TObjectPtr<class USpringArmComponent> SpringArmComponent_;
	UPROPERTY()
	TObjectPtr<class UCameraComponent> CameraComponent_;
	UPROPERTY()
	TObjectPtr<class UNavigationComponent> NavigationComponent_;
};