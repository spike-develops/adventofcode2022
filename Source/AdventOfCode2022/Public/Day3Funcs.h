// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Day3Funcs.generated.h"

/**
 * 
 */
UCLASS()
class ADVENTOFCODE2022_API UDay3Funcs : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()


	UFUNCTION(BlueprintCallable, Category=Advent)
	static int FindMatchingPriority(TArray<int> items1, TArray<int> items2);

	
	UFUNCTION(BlueprintCallable, Category=Advent)
	static int FindMatchingPriorityTriple(TArray<int> items1, TArray<int> items2, TArray<int> items3);
	
	UFUNCTION(BlueprintCallable, Category=Advent)
	static void GetPriorityArraysFromString(FString compartment1, TArray<int>& items1);


	UFUNCTION(BlueprintCallable, Category=Advent)
	static FString GetStringFromPriority(int priority);
	
	static int ConvertCharToPriority(char input);
	
};
