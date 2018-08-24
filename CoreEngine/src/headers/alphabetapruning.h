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
#define LINE_NUM  15
#define XLINE_NUM 29
#define VLINE_NUM LINE_NUM
#define HLINE_NUM LINE_NUM
#define RLINE_NUM XLINE_NUM
#define LLINE_NUM XLINE_NUM

//#define HDIR 0
//#define VDIR 1
//#define RDIR 2
//#define LDIR 3

typedef enum _DIR
{
HDIR,
VDIR,
RDIR,
LDIR
} DIR;

typedef s8 LINE[BOARD_SIZE];
typedef s8 LINE2D[BOARD_SIZE][BOARD_SIZE];

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

#define DEBUG_ALPHA 1

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
private:
	s8 whole_board[BOARD_SIZE][BOARD_SIZE];
	s8 hline[HLINE_NUM][BOARD_SIZE];
	s8 vline[VLINE_NUM][BOARD_SIZE];
	s8 rline[RLINE_NUM][BOARD_SIZE];
	s8 lline[LLINE_NUM][BOARD_SIZE];
private:
	Analysisline* lineAnalysis;	
private:
	void copy_a_line(s8 line_dst[],s8 board[][BOARD_SIZE],int num, DIR dir);
	void line_to_line(LINE& line1,s8 line2[BOARD_SIZE]);
public:
	void copy_from_board(const s8 board[][BOARD_SIZE]);
	int scores_of_players(char player);
public:
	void board_to_line();
	void get_a_line(LINE& line,int num,DIR dir);
#ifdef DEBUG_ALPHA
public:
	void dis_lines(s8 lines[][BOARD_SIZE],int num, DIR dir);
	void dis_a_line(LINE& line);
#endif
};

class AlphaBetaPruning
{
private:
	s8 board_for_pruning[BOARD_SIZE][BOARD_SIZE];
	Evaluate* evaluate;
public:
	AlphaBetaPruning();
	~AlphaBetaPruning();
public:
	void display_line_info();
public:
	void loadBoard(const Chessboard& board);
	
};
#endif

