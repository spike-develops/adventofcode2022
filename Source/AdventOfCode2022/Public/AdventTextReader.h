// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include <Runtime/Core/Public/Misc/FileHelper.h>
#include "AdventTextReader.generated.h"

/**
 * 
 */
UCLASS()
class ADVENTOFCODE2022_API UAdventTextReader : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
	UFUNCTION(BlueprintCallable, Category = "File I/O")
	static FString LoadFileToString(FString Filename);

	UFUNCTION(BlueprintCallable, Category=Advent)
	static void ParseIntsByDelimiters(FString inputString,TArray<FString> delimiters,TArray<int>& foundInts, bool remainderInclusive);
};