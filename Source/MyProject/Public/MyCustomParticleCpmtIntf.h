// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CustomParticleCpmtIntf.h"
#include "MyCustomParticleCpmtIntf.generated.h"
/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class MYPROJECT_API UMyCustomParticleCpmtIntf : public UCustomParticleCpmtIntf
{
	GENERATED_BODY()
	
public:
	void Go() override;
	void Stop() override;
	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
public: //ctor
	UMyCustomParticleCpmtIntf();
};
