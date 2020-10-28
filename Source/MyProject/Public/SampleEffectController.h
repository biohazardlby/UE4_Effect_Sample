// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CustomParticleCpmtIntf.h"
#include "SampleEffectController.generated.h"



UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MYPROJECT_API USampleEffectController : public UActorComponent
{
	GENERATED_BODY()

public:	
	USampleEffectController();

	//vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv// handle to import actor
	UPROPERTY(EditAnywhere)
		AActor* particle_actor;

private: 
	UCustomParticleCpmtIntf* pc;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
		
};
