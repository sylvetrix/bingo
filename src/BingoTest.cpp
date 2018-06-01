#include <iostream>
#include <iomanip>

#include "BingoCard.h"

using std::cout;

int
main(int argc, char** argv)
{
	BingoCard card = BingoCard();

	card.printCard(cout);
	cout << "\n";
	card.printCardMarks(cout);

	return 0;
}
