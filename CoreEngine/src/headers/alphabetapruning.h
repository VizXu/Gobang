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
class AlphaBetaPruning
{
private:
	s8 board_for_pruning[BOARD_SIZE][BOARD_SIZE];
public:
	void loadBoard(const Chessboard& board);
	
};
#endif

