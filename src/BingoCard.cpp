#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "BingoCard.h"

using std::ostream;

BingoCard::BingoCard()
{
	int nums[15];

	for (int i = 0; i < 5; i++)
	{
		int j;
		// fill nums array
		for (j = 0; j < 15; j++)
		{
			nums[j] = j + 1 + (i * 15);
		}

		// Knuth shuffle
		srand(time(NULL));
		for (j = 14; j >= 1; j--)
		{
			int r = rand() % (j + 1);
			
			// swap
			int tmp = nums[j];
			nums[j] = nums[r];
			nums[r] = tmp;
		}

		// grab first 5 numbers from random list for card
		for (j = 0; j < 5; j++)
		{
			squares[i][j].marked = false;
			squares[i][j].value = nums[j];
		}
	}

	// set free square to 0 and marked
	squares[2][2].marked = true;
	squares[2][2].value = 0;
}

int
BingoCard::getSquare(int i, int j)
{
	if ((i < 0) || (i > 4) || (j < 0) || (j > 4))
	{
		return -1;
	}

	return squares[i][j].value;
}

bool
BingoCard::isSquareMarked(int i, int j)
{
	if ((i < 0) || (i > 4) || (j < 0) || (j > 4))
	{
		return false;
	}

	return squares[i][j].marked;
}

void
BingoCard::printCard(ostream &stream)
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if ((i == 2) && (j == 2))
			{
				stream << "Fr";
			}
			else
			{
				stream << std::setw(2) << squares[j][i].value;
			}
			stream << " ";
		}
		stream << "\n\n";
	}
}

void
BingoCard::printCardMarks(ostream &stream)
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			stream << (squares[j][i].marked ? "X " : "_ ");
		}
		stream << "\n\n";
	}
}
