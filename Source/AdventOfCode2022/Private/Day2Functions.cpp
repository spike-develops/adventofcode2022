// Fill out your copyright notice in the Description page of Project Settings.


#include "Day2Functions.h"

void UDay2Functions::DetermineRochambeauOutcome(FString input, TEnumAsByte<RochambeauThrow>& playerThrow, TEnumAsByte<RochambeauOutcome>& outcome)
{
	RochambeauThrow oppThrow = ProcessThrow(input[0]);
	playerThrow = ProcessThrow(input[2]);

	if(
		(playerThrow == Rock && oppThrow == Scissors)||
		(playerThrow == Scissors && oppThrow == Paper)||
		(playerThrow == Paper && oppThrow == Rock))
	{
		outcome = Win;
	}else if (
		(playerThrow == Rock && oppThrow == Paper)||
		(playerThrow == Paper && oppThrow == Scissors)||
		(playerThrow == Scissors && oppThrow == Rock))
	{
		outcome = Loss;
	}
	else
	{
		//its a tie
		outcome = Tye;
	}
}

void UDay2Functions::DetermineRochambeauThrow(FString input, TEnumAsByte<RochambeauThrow>& playerThrow, TEnumAsByte<RochambeauOutcome>& outcome)
{
	RochambeauThrow oppThrow = ProcessThrow(input[0]);
	outcome = ProcessOutcome(input[2]);

	if(
		(outcome == Win && oppThrow == Scissors)||
		(outcome == Loss && oppThrow == Paper)||
		(outcome == Tye && oppThrow == Rock))
	{
		playerThrow = Rock;
	}else if (
		(outcome == Win && oppThrow == Paper)||
		(outcome == Tye && oppThrow == Scissors)||
		(outcome == Loss && oppThrow == Rock))
	{
		playerThrow = Scissors;
	}
	else
	{
		//its a tie
		playerThrow = Paper;
	}
}


TEnumAsByte<RochambeauThrow> UDay2Functions::ProcessThrow(char input)
{
	switch (input)
	{
		case 'X':
		case 'A':
			return Rock;
		case 'Y':
		case 'B':
			return Paper;
		case 'Z':
		case 'C':
			return Scissors;
		default:
			return DefaultZero;
	}
}

TEnumAsByte<RochambeauOutcome> UDay2Functions::ProcessOutcome(char input)
{
	switch (input)
	{
	case 'X':
	case 'A':
		return Loss;
	case 'Y':
	case 'B':
		return Tye;
	case 'Z':
	case 'C':
		return Win;
	default:
		return Loss;
	}
}
