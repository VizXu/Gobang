#ifndef CHESSBOARD_H_
#define CHESSBOARD_H_

#include "types.h"
#define BOARD_SIZE 8

class ChessBoard
{
private:
  s8 chessboard[BOARD_SIZE][BOARD_SIZE];
private:
  void set_chess(u32,u32);
public:
  u32 total_empty_site();
  bool is_empty_site(u32,u32);
public:
  ChessBoard(){
    for(int i=0;i<BOARD_SIZE;i++){
      for(int j=0;j<BOARD_SIZE;j++){
         this->chessboard[i][j] = '+';
      }
    }
  }
  ~ChessBoard(){}
public:
  ChessBoard& operator()(const ChessBoard&) = delete;
  ChessBoard(const ChessBoard&) = delete;
  ChessBoard& operator=(const ChessBoard&) = delete;
};
#endif //chessboard.h
