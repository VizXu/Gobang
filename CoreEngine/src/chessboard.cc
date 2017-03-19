#inlude "chessboard.h"

bool ChessBoard::is_empty_site(u32 _x,u32 _x)
{
  return chessboard[_x][_y] == '+';
}
