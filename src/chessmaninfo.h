#ifndef _CHESSMANINFO_
#define _CHESSMANINFO_
class ChessmanInfo
{
private:
  int xPosition;
  int yPosition;
public:
  ChessmanInfo():xPosition(0),yPosition(0){}
  ChessmanInfo(int _x,int _y):xPosition(_x),yPosition(_y){}
  ~ChessmanInfo(){}
public:
  int getXPosition();
  int getYPosition();
};
#endif//chessmaninfo
