#ifndef BINGOCARD_H
#define BINGOCARD_H

#include <iostream>

using std::ostream;

class BingoCard
{
	public:
		BingoCard();
		int getSquare(int);
		int getSquare(int, int);
		bool isSquareMarked(int);
		bool isSquareMarked(int, int);
		void printCard(ostream &);
		void printCardMarks(ostream &);
		static bool invalidCoord(int);
		static bool invalidCoord(int, int);

	private:
		struct BingoSquare
		{
			bool marked;
			int value;
		};
		BingoSquare squares[25];
};

#endif	// BINGOCARD_H
