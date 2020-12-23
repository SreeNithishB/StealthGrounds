// Fill out your copyright notice in the Description page of Project Settings.


#include "ChooseNextWayPoint.h"
#include "AIController.h"
#include "PatrolRoute.h"
#include "BehaviorTree/BlackboardComponent.h"

EBTNodeResult::Type UChooseNextWayPoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	//Get the patrol points
	auto AIController = OwnerComp.GetAIOwner();
	auto ControlledPawn = AIController->GetPawn();
	auto PatrolRoute = ControlledPawn->FindComponentByClass<UPatrolRoute>();

	if (!ensure(PatrolRoute)) { EBTNodeResult::Failed; }

	//warn about empty patrol route
	auto PatrollingPoints = PatrolRoute->GetPatrolPoints();
	if (PatrollingPoints.Num() == 0) 
	{
		UE_LOG(LogTemp, Warning, TEXT("No Patrol Points found for %s!"), *ControlledPawn->GetName());
		EBTNodeResult::Failed;
	}


	//set next way poin
	auto BlackboardComp = OwnerComp.GetBlackboardComponent();
	auto Index = BlackboardComp->GetValueAsInt(IndexKey.SelectedKeyName);
	BlackboardComp->SetValueAsObject(WayPointKey.SelectedKeyName, PatrollingPoints[Index]);

	//cycle the index
	auto NextIndex = (Index + 1) % PatrollingPoints.Num();
	BlackboardComp->SetValueAsInt(IndexKey.SelectedKeyName, NextIndex);

	return EBTNodeResult::Succeeded;

}
