// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Day2Functions.generated.h"



UENUM(BlueprintType)
enum RochambeauThrow
{
	DefaultZero = 0,
	Rock=1 UMETA(DisplayName = "rockk"), 
	Paper=2 UMETA(DisplayName = "papper"),
	Scissors=3 UMETA(DisplayName = "scisssors")
};

UENUM(BlueprintType)
enum RochambeauOutcome
{
	Loss = 0 UMETA(DisplayName = "lose"), 
	Tye = 3 UMETA(DisplayName = "tie"),
	Win=6 UMETA(DisplayName = "win")
};

/**
 * 
 */
UCLASS()
class ADVENTOFCODE2022_API UDay2Functions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
	
	UFUNCTION(BlueprintCallable,Category=Advent)
	static void DetermineRochambeauOutcome(FString input,TEnumAsByte<enum RochambeauThrow>& playerThrow, TEnumAsByte<enum RochambeauOutcome>& outcome);
};
