#include "alphabetapruning.h"

void Analysisline::loadaLine(s8 * line)
{
return;
}

void AlphaBetaPruning::loadBoard(const Chessboard& board)
{
   for(int i = 0;i < BOARD_SIZE; i++){
        for(int j = 0; j < BOARD_SIZE; j++){
           this->board_for_pruning[i][j]= board.get_chess(i,j);
 	}
   }
}
