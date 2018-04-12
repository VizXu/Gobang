#include <iostream>
#include "chessboard.h"
#include "debug.h"

void display_chessboard(const Chessboard& board)
{
  int s = 0;
  for(int i = 0; i < BOARD_SIZE; i++){
    for(int j = 0;j < BOARD_SIZE; j++){
      if(i == 0 && j == 0) {
         for(;s < BOARD_SIZE; s++)
         std::cout<<"   "<<s;
         std::cout<<std::endl;
      }
      if(j == 0) std::cout<<i<<'|';
      if(j == 0) std::cout<<' ';
      std::cout<<board.get_chess(i,j)<<"   ";
    }
    std::endl(std::cout);
    std::endl(std::cout);
  }
  s = 0;
}

