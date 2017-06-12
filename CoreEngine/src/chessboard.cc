#include "chessboard.h"

u32 Chessboard::scan_board() const
{
   u32 empty_site = 0;
   for(int i = 0;i < BOARD_SIZE;i++){
     for(int j = 0; j < BOARD_SIZE; j++){
       if('+' == board[i][j]) 
	 empty_site++;
       else continue;
     }
   }
return empty_site;
}

bool Chessboard::is_board_empty() const
{
  if(BOARD_SIZE*BOARD_SIZE == this->scan_board()) return true;
  else return false;
}

bool Chessboard::is_site_empty(u32 x_pos,u32 y_pos) const
{
   if(x_pos > BOARD_SIZE || y_pos > BOARD_SIZE) return false;
   if(this->board[x_pos][y_pos] == '+')return true;
   else return false;
}

bool Chessboard::set_chess(u32 x_pos,u32 y_pos,s8 chess_type)
{
  if(is_site_empty(x_pos,y_pos)){
    this->board[x_pos][y_pos] = chess_type;
    return true;
  }
return false;
}

s8  Chessboard::get_chess(u32 x_pos,u32 y_pos) const
{
    if(x_pos > BOARD_SIZE || y_pos > BOARD_SIZE) throw "out of range";
    return this->board[x_pos][y_pos];
}

int Chessboard::store_chess_info(const std::string& file_name)
{
   StoreChessManual* s = StoreChessManual::get_chess_manual();
}

chessboard_info&& Chessboard::get_chessboard()
{
  chessboard_info chessboard_to_store;
  for(int i = 0; i< BOARD_SIZE; i++){
    for(int j = 0; j< BOARD_SIZE; j++){
       chessboard_to_store[i][j] = this->board[i][j];
    }
  }
return std::move(chessboard_to_store);
}

