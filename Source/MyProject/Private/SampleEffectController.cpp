
#include "SampleEffectController.h"

USampleEffectController::USampleEffectController()
{
	PrimaryComponentTick.bCanEverTick = true;
}


// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv //
// How to get our UCustomParticleCpmntIntf from actor
void USampleEffectController::BeginPlay()
{
	if (particle_actor) {
		TArray<UCustomParticleCpmtIntf*> pcs;
		particle_actor->GetComponents<UCustomParticleCpmtIntf>(pcs, true);
		pc = *pcs.GetData();
	}
}


// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv //
// How to start them and stop them 
void USampleEffectController::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	if (particle_actor) {
		if (pc) {
			if (GetWorld()->GetFirstPlayerController()->WasInputKeyJustPressed(FKey(TEXT("g")))) {
				pc->Go();
			}
			if (GetWorld()->GetFirstPlayerController()->WasInputKeyJustPressed(FKey(TEXT("s")))) {
				pc->Stop();
			}
		}
	}
}
