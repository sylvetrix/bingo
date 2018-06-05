#ifndef BINGOENGINE_H
#define BINGOENGINE_H

class BingoEngine
{
	public:
		BingoEngine();
		
	private:
		bool calledList[75];
		int cageList[75];
		int cageListPos = 0;
};

#endif // BINGOENGINE_H
