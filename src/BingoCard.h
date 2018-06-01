#ifndef BINGOCARD_H
#define BINGOCARD_H

#include <iostream>

using std::ostream;

class BingoCard
{
	public:
		BingoCard();
		int getSquare(int, int);
		bool isSquareMarked(int, int);
		void printCard(ostream &);
		void printCardMarks(ostream &);

	private:
		struct BingoSquare
		{
			bool marked;
			int value;
		};
		BingoSquare squares[5][5];
};

#endif	// BINGOCARD_H
