#ifndef BINGOENGINE_H
#define BINGOENGINE_H

class BingoEngine
{
	public:
		enum Pattern
		{
			ROW_0,
			ROW_1,
			ROW_2,
			ROW_3,
			ROW_4,
			COL_0,
			COL_1,
			COL_2,
			COL_3,
			COL_4,
			FOUR_CORNERS,
			STANDARD_NO_CORNERS,
			STANDARD,
			PATTERN_DELIMITER
		};

		BingoEngine();
		~BingoEngine();
		
	private:
		struct BingoPattern
		{
			int patternCount;
			unsigned int *patterns;
		};
		BingoPattern * bingoPatterns;
		unsigned int patternFlags[25];

		bool calledList[75];
		int cageList[75];
		int cageListPos;

		void initializeCage();
		void initializePatterns();
};

#endif // BINGOENGINE_H
