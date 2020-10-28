// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "Particles/ParticleSystem.h"
#include "NiagaraSystem.h"
#include "NiagaraComponent.h"

#include "CustomParticleCpmtIntf.generated.h"


UCLASS(abstract)
class MYPROJECT_API UCustomParticleCpmtIntf : public USceneComponent
{
	GENERATED_BODY()

public:	//stats

	UPROPERTY(EditAnywhere)
		UParticleSystem* cascade_particle_system;
	UPROPERTY(EditAnywhere)
		UNiagaraSystem* niagara_particle_system;
	UPROPERTY(EditDefaultsOnly)
		UParticleSystemComponent* cascade_particle_system_cpmnt;
	UPROPERTY(EditDefaultsOnly)
		UNiagaraComponent* niagara_particle_system_cpmnt;

public:
	UCustomParticleCpmtIntf();

	// start particle
	virtual void Go() PURE_VIRTUAL(ASpawnVolume::CanRedo, );
	// Stop particle
	virtual void Stop() PURE_VIRTUAL(ASpawnVolume::CanRedo, );


protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;


};
