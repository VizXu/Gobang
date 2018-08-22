#include "chessboard.h"
#include "types.h"
#include <ctime>
#include <cstdlib>
#include <list>
#include <vector>
#include <exception>
#include "boardposition.h"

#ifndef ALPHABETAPRUNING
#define ALPHABETAPRUNING

#define LINE_SIZE 15
#define VLINE_NUM 15
#define HLINE_NUM 15
#define RLINE_NUM 29
#define LLINE_NUM 29

#define HDIR 0
#define VDIR 1
#define RDIR 2
#define LDIR 3

/*
FIVE:
	@@@@@   // 9999
FOUR:
	-@@@@-  // 9998
GFORN:
	#@@@@-  // 4999 
	-@@@@#  // 4999
	@@@-@   // 4999 
	@-@@@   // 4999
	@-@@@-@ // 9998 double gfour
	@@-@@   // 4999
       @@-@@-@@ // 9998 double gfour
       @@-@@-@- // 4999 + 1249 
THREE:
	-@@@-   // 2499
GTHREE:
	-@@-@    // 1249
	-@-@@    // 1249
	@--@@    // 1248
	@--@@--@ // 2498
TWO:
	--@@-  // 624
	-@-@-  // 620
	@-@-@  // 1248  double two
GTWO:
	-@--@  // 311
ONE:
	--@--  // 100

*/

class Analysisline
{
private:
	s8 a_line[LINE_SIZE];
	char player;
	char enemy_player;
public:
	void playerIs(char player);
	void loadaLine(s8* line);
};

class Evaluate
{
public:
	s8 wholeBoard[BOARD_SIZE][BOARD_SIZE];
	s8 vline[VLINE_NUM][BOARD_SIZE];
	s8 hline[HLINE_NUM][BOARD_SIZE];
	s8 rline[RLINE_NUM][BOARD_SIZE];
	s8 lline[LLINE_NUM][BOARD_SIZE];
private:
	Analysisline* lineAnalysis;	
public:
	int scores_of_players(char player);
	void board_to_a_line(s8* line,int num, int direction);
};

class AlphaBetaPruning
{
private:
	s8 board_for_pruning[BOARD_SIZE][BOARD_SIZE];
	Evaluate* evaluate;
public:
	void loadBoard(const Chessboard& board);
	
};
#endif

