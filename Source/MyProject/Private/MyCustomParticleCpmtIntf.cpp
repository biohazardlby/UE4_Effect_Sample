// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCustomParticleCpmtIntf.h"
#include "UObject/UObjectGlobals.h"
#include "NiagaraSystem.h"
#include "NiagaraComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "Particles/ParticleSystem.h"

void UMyCustomParticleCpmtIntf::Go()
{
	if (cascade_particle_system_cpmnt) {
		cascade_particle_system_cpmnt->SetActive(true);
	}
	if (niagara_particle_system_cpmnt) {
		niagara_particle_system_cpmnt->SetActive(true);
	}
}

void UMyCustomParticleCpmtIntf::Stop()
{
	if (cascade_particle_system_cpmnt) {
		cascade_particle_system_cpmnt->SetActive(false);
	}
	if (niagara_particle_system_cpmnt) {
		niagara_particle_system_cpmnt->SetActive(false);
	}
}

void UMyCustomParticleCpmtIntf::BeginPlay()
{
	UE_LOG(LogTemp, Warning, TEXT("I just started running"));
	PrimaryComponentTick.bCanEverTick = true;
	if (cascade_particle_system) {
		cascade_particle_system_cpmnt = NewObject<UParticleSystemComponent>(this, TEXT("Cascade_Particle_System_Component"));
		if (cascade_particle_system_cpmnt) {
			cascade_particle_system_cpmnt->RegisterComponent();
			cascade_particle_system_cpmnt->AttachTo(this);
			cascade_particle_system_cpmnt->SetTemplate(cascade_particle_system);
			cascade_particle_system_cpmnt->Deactivate();
		}
	}
	if (niagara_particle_system) {
		niagara_particle_system_cpmnt = NewObject<UNiagaraComponent>(this, TEXT("Niagara_Particle_System_Component"));
		if (niagara_particle_system_cpmnt) {
			niagara_particle_system_cpmnt->RegisterComponent();
			niagara_particle_system_cpmnt->AttachTo(this);
			niagara_particle_system_cpmnt->SetAsset(niagara_particle_system);
			niagara_particle_system_cpmnt->Deactivate();
		}
	}
	
}

void UMyCustomParticleCpmtIntf::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{

}

UMyCustomParticleCpmtIntf::UMyCustomParticleCpmtIntf()
{
}