// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "BlasterCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UInputAction;
class UInputMappingContext;
class UWidgetComponent;
class AWeapon;

UCLASS()
class BLASTERGAME_API ABlasterCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABlasterCharacter();
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	virtual void PostInitializeComponents() override;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	
	UPROPERTY(EditAnywhere, Category = Input)
	UInputMappingContext* BlasterContext;

	UPROPERTY(EditAnywhere, Category = Input)
	UInputAction* MovementAction;

	UPROPERTY(EditAnywhere, Category = Input)
	UInputAction* LookAction;
	
	UPROPERTY(EditAnywhere, Category = Input)
	UInputAction* JumpAction;

	UPROPERTY(EditAnywhere, Category = Input)
	UInputAction* EquipAction;

	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UWidgetComponent* OverheadWidget;

	UPROPERTY(ReplicatedUsing = OnRep_OverlappingWeapon)
	AWeapon* OverlappingWeapon;

	UFUNCTION()
	void OnRep_OverlappingWeapon(AWeapon* LastWeapon);

	void EquipButtonPressed();

private:


	UPROPERTY(EditDefaultsOnly, Category = Camera)
	USpringArmComponent* CameraBoom;

	UPROPERTY(EditDefaultsOnly, Category = Camera)
	UCameraComponent* FollowCamera;

	UPROPERTY(VisibleAnywhere)
	class UCombatComponent* Combat;

public:	
	//FORCEINLINE void SetOverlappingWeapon(AWeapon* Weapon) {OverlappingWeapon = Weapon;}
	/* as soon as the value of overlapping weapon changes, then it will replicate, 
	which means the variable will be set on all client blaster characters.*/
	void SetOverlappingWeapon(AWeapon* Weapon);

};
