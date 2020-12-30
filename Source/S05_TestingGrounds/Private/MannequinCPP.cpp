// Fill out your copyright notice in the Description page of Project Settings.


#include "MannequinCPP.h"

// Sets default values
AMannequinCPP::AMannequinCPP()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMannequinCPP::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMannequinCPP::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMannequinCPP::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

