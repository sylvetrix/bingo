#ifndef BINGOPATTERN_H
#define BINGOPATTERN_H

class BingoPattern
{
	public:

	private:
		class BPInit
		{
			public:
				BPInit();
		};

		friend class BPInit;
		unsigned int flags[25];

		static BPInit bpInit;
};

#endif // BINGOPATTERN_H
