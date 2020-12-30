// Fill out your copyright notice in the Description page of Project Settings.


#include "MannequinCPP.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Gun.h"

// Sets default values
AMannequinCPP::AMannequinCPP()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CameraFP = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	CameraFP->SetupAttachment(GetCapsuleComponent());
	CameraFP->SetRelativeLocation(FVector(-39.56f, 1.75f, 64.f)); // Position the camera
	CameraFP->bUsePawnControlRotation = true;

	FPArms = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("CharacterMesh1P"));
	FPArms->SetOnlyOwnerSee(true);
	FPArms->SetupAttachment(CameraFP);
	FPArms->bCastDynamicShadow = false;
	FPArms->CastShadow = false;
	FPArms->SetRelativeRotation(FRotator(1.9f, -19.19f, 5.2f));
	FPArms->SetRelativeLocation(FVector(-0.5f, -4.4f, -155.7f));

}

// Called when the game starts or when spawned
void AMannequinCPP::BeginPlay()
{
	Super::BeginPlay();

	if (GunBlueprint == NULL)
	{
		UE_LOG(LogTemp, Warning, TEXT("GunBlueprint is NULL"));
		return;
	}
	Gun = GetWorld()->SpawnActor<AGun>(GunBlueprint);
	Gun->AttachToComponent(FPArms, FAttachmentTransformRules(EAttachmentRule::SnapToTarget, true), TEXT("GripPoint"));
	Gun->AnimInstance = FPArms->GetAnimInstance();

	// Bind fire event
	//InputComponent->BindAction("Fire", IE_Pressed, Gun, &AGun::OnFire);
	
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

void AMannequinCPP::Fire()
{
	Gun->OnFire();
}

