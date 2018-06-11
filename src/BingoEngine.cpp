#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "BingoEngine.h"

BingoEngine::BingoEngine()
{
	initializeCage();
	initializePatterns();
}

void
BingoEngine::initializePatterns()
{
	// initialize pattern flags
	for (int i = 0; i < 25; i++)
	{
		patternFlags[i] = 1 << i;
	}

	// create patterns
	unsigned int flag;
	BingoPattern * cp;	// pointer to current pattern
	bingoPatterns = new BingoPattern[PATTERN_DELIMITER];

	// create rows
	for (int i = ROW_0; i <= ROW_4; i++)
	{
		flag = 0;
		cp = &bingoPatterns[i];
		cp->patternCount = 1;
		cp->patterns = new unsigned int[1];
		for (int j = 0; j < 25; j += 5)
		{
			flag |= patternFlags[j];
		}
		cp->patterns[0] = flag;
	}

	// create columns
	for (int i = COL_0; i <= COL_4; i++)
	{
		flag = 0;
		cp = &bingoPatterns[i];
		cp->patternCount = 1;
		cp->patterns = new unsigned int[1];
		for (int j = 0; j < 5; j++)
		{
			flag |= patternFlags[j+i*5];
		}
		cp->patterns[0] = flag;
	}

	// create four corners
	cp = &bingoPatterns[FOUR_CORNERS];
	cp->patternCount = 1;
	cp->patterns = new unsigned int[1];
	cp->patterns[0] =
		patternFlags[0]		// 0,0
		| patternFlags[4]	// 4,0
		| patternFlags[20]	// 0,4
		| patternFlags[24];	// 4,4

	// create standard (without four corners)
	cp = &bingoPatterns[STANDARD_NO_CORNERS];
	cp->patternCount = 10;
	cp->patterns = new unsigned int[10];
	for (int i = ROW_0, j = 0; i <= COL_4; i++, j++)
	{
		cp->patterns[j] = bingoPatterns[i].patterns[0];
	}

	// create standard
	cp = &bingoPatterns[STANDARD];
	cp->patternCount = 11;
	cp->patterns = new unsigned int[11];
	for (int i = 0; i < 10; i++)
	{
		cp->patterns[i] = bingoPatterns[STANDARD_NO_CORNERS].patterns[i];
	}
	cp->patterns[10] = bingoPatterns[FOUR_CORNERS].patterns[0];
}

void
BingoEngine::initializeCage()
{
	// populate lists
	for (int i = 0; i < 75; i++)
	{
		calledList[i] = false;
		cageList[i] = i + 1;
	}

	// Knuth shuffle
	srand(time(NULL));
	for (int j = 74; j >= 1; j--)
	{
		int r = rand() % (j + 1);

		// swap
		int tmp = cageList[j];
		cageList[j] = cageList[r];
		cageList[r] = tmp;
	}	
}

