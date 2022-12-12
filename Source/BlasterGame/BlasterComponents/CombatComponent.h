// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CombatComponent.generated.h"

class AWeapon;
class ABlasterCharacter;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BLASTERGAME_API UCombatComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	
	UCombatComponent();
	friend class ABlasterCharacter;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void EquipWeapon(AWeapon* WeaponToEquip);
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
protected:

	virtual void BeginPlay() override;


private:

	ABlasterCharacter* Character;

	/* equip weapon is only sent on the server, which means we're only setting equipped 
	weapon on the server and equipped weapon is not replicated well since our enemy 
	instance needs to know if we have an equipped weapon so all clients can be in
	the correct animation poses on all machines.*/
	UPROPERTY(Replicated)
	AWeapon* EquippedWeapon;

public:	
	
	
		
};
