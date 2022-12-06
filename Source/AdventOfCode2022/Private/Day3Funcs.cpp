// Fill out your copyright notice in the Description page of Project Settings.


#include "Day3Funcs.h"


void UDay3Funcs::GetPriorityArraysFromString(FString compartment1, TArray<int>& items1)
{
	items1 = TArray<int>();
	//items2 = TArray<int>();
	items1.Init(0,53);
	//items2.Init(0,53);
	
	for (int i = 0; i<compartment1.Len(); i++)
	{
		char chr1 =compartment1[i];
		//char chr2 =compartment2[i];

		int index1 = ConvertCharToPriority(chr1);
		//int index2 = ConvertCharToPriority(chr2);

		items1[index1] = items1[index1]+1;
		//items2[index2] = items2[index2]+1;
	}
}

FString UDay3Funcs::GetStringFromPriority(int priority)
{
	if(priority<27)
	{
		priority = priority + 'a';
		priority--;

	}else
	{
		priority = priority + 'A';
		priority = priority -27;
	}
	char ch = static_cast<char>(priority);

	return FString::Chr(ch);
}

int UDay3Funcs::FindMatchingPriority(TArray<int> items1, TArray<int> items2)
{
	for(int i = 1; i<=52; i++)
	{
		if(items1[i]>0 && items2[i]>0)
		{
			return i;
		}
	}
	return -1;
}

int UDay3Funcs::FindMatchingPriorityTriple(TArray<int> items1, TArray<int> items2, TArray<int> items3)
{
	for(int i = 1; i<=52; i++)
	{
		if(items1[i]>0 && items2[i]>0 && items3[i]>0)
		{
			return i;
		}
	}
	return -1;
}



int UDay3Funcs::ConvertCharToPriority(char input)
{
	int asciiCode =  input;

	if(asciiCode>96 && asciiCode < 123)
	{
		//its lowercase
		//"zero" it out
		asciiCode= asciiCode-'a';
		//add one, so a-z -> 1-26
		asciiCode++;
		return asciiCode;
	}
	else if (asciiCode >64 && asciiCode < 91)
	{
		//its uppercase
		//"zero" it out
		asciiCode= asciiCode-'A';
		//add 27 so A-Z is 27-52
		asciiCode +=27;
		return asciiCode;
		//
	}
	else
	{
		//failstate
		return -1;
	}
}
