// Fill out your copyright notice in the Description page of Project Settings.



#include "AdventTextReader.h"

#include <execution>
#include <Runtime/Core/Public/Misc/Paths.h>
#include <Runtime/Core/Public/HAL/PlatformFileManager.h>

#include "Misc/DefaultValueHelper.h"


FString UAdventTextReader::LoadFileToString(FString Filename)
{
	FString directory = FPaths::ProjectContentDir();
	FString result;
	IPlatformFile& file = FPlatformFileManager::Get().GetPlatformFile();

	if(file.CreateDirectory(*directory))
	{
		FString myFile = directory + "/" + Filename;
		FFileHelper::LoadFileToString(result, *myFile);
	}
	return result;
}

void UAdventTextReader::ParseIntsByDelimiters(FString inputString, TArray<FString> delimiters, TArray<int>& foundInts, bool remainderInclusive)
{
	//create an int array of equal size (since we'll assume the last delimiter is \n) ?
	foundInts = TArray<int>();

	if(remainderInclusive)
	{
		foundInts.Init(-1,delimiters.Num()+1);
	}
	else
	{
		foundInts.Init(-1,delimiters.Num());
	}

	
	//if this works, i'll chuckle
	FString remainderString;
	for(int i = 0; i< delimiters.Num(); i++)
	{
		FString strToParse;
		inputString.Split(delimiters[i],&strToParse, &remainderString);

		if(int parsedInt = -1; FDefaultValueHelper::ParseInt(strToParse,parsedInt))
		{
			foundInts[i] = parsedInt;
		}
		else
		{
			return;
		}
		
		//make the input string equal to remainder (so we dont keep processing the start of the string
		inputString = remainderString;
	}

	if(remainderInclusive)
	{
		if(int parsedInt = -1; FDefaultValueHelper::ParseInt(inputString,parsedInt))
		{
			foundInts[delimiters.Num()] = parsedInt;
		}
	}
}
