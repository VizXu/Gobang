#include "testwinner.h"

#include "debug.h"

bool Testwinner::operator()(const Chessboard& chessboard,const board_position& position,s8 chess_type)
{
   ai->copy_board(chessboard);
   return ai->is_winner(position,chess_type);
}
