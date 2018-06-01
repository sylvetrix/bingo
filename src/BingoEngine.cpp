#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "BingoEngine.h"

BingoEngine::BingoEngine()
{
	// populate lists
	for (int i = 0; i < 75; i++)
	{
		calledList[i] = false;
		cageList[i] = i + 1;
	}

	// Knuth shuffle
	srand(time(NULL));
	for (j = 74; j >= 1; j--)
	{
		int r = rand() % (j + 1);

		// swap
		int tmp = cageList[j];
		cageList[j] = cageList[r];
		cageList[r] = tmp;
	}
}
