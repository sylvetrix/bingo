#include "BingoPattern.h"

BingoPattern::BPInit::BPInit()
{
	for (int i = 0; i < 25; i++)
	{
		BingoPattern::flags[i] = 1 << i;
	}
}

