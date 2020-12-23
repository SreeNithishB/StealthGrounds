// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "/Users/sreen/Documents/Gaming With Unreal/UnrealCourse/S05_TestingGrounds/Source/S05_TestingGrounds/TP_ThirdPerson/TP_ThirdPersonCharacter.h"
#include "PatrollingGaurd.generated.h"




/**
 * 
 */
UCLASS()
class S05_TESTINGGROUNDS_API APatrollingGaurd : public ATP_ThirdPersonCharacter
{
	GENERATED_BODY()

	UPROPERTY(EditInstanceOnly, Category = "Patrol Routes")
	TArray<AActor*> PatrolPointsCPP;
	

};
