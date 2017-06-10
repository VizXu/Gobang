#include "player.h"
#include "storechessmanual.h"

Player::Player(const string& s):player_name(s)
{
  
  start_time = time(NULL);
  end_time = time(NULL);
  use_time = end_time - start_time;
  move_state = stop;
  present_position.x_pos = 0;
  present_position.y_pos = 0;
  last_position.x_pos = 0;
  last_position.y_pos = 0;
  suggest_position.x_pos = 0;
  suggest_position.y_pos = 0;
}

Player::~Player()
{

}

board_position Player::get_present_position()
{
   return this->present_position;
}

bool Player::make_a_step(Chessboard& chessboard)
{
     StoreChessManual* s = StoreChessManual::get_chess_manual();

     if(this->player_name == "computer")
       return chessboard.set_chess(this->suggest_position.x_pos,this->suggest_position.y_pos,'@');
     else return false;
}

void Player::analysis(Chessboard& chessboard,AI_core& ai,u32 level)
{
  // none compeletion
}

string Player::get_player_name()
{
  return this->player_name;
}
