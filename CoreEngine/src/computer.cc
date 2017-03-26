#include"computer.h"

Computer::Computer(string s):Player("computer"),computer_name(s)
{
   level = 1;
   this->ai = new AI_core();
}

Computer::~Computer()
{
   delete ai;
}

State Computer::change_state()
{
   if(this->move_state == stop){
      this->move_state = start;
      return start;
   }
   else{
      this->move_state = stop;
      return stop;
   }
}

board_position Computer::get_present_position()
{
   return this->present_position;
}

bool Computer::make_a_step(Chessboard& chessboard)
{
   if(this->move_state  == start){
      u32 lvr = this->level;
      ai_analysis(chessboard,lvr);
      if(chessboard.set_chess(suggest_position.x_pos,suggest_position.y_pos,'@')){
         this->last_position = this->present_position;
	 this->present_position = this->suggest_position;
      }
    }
    else{
       return false;
    }
}

void Computer::ai_analysis(Chessboard& chessboard,u32 level)
{
   ai->copy_board(chessboard);
   
   switch(level)
   {
     case 1:ai->analyze_level1('&');break;
     case 2:ai->analyze_level1('@');break;
     case 3:ai->analyze_level1('@');break;
     default:break;
   }
   this->suggest_position = ai->get_suggest_position();
   this->present_position = this->suggest_position;
}

string Computer::get_name()
{
  return get_player_name();
}

void Computer::select_level(u32 l)
{
  this->level = l;
}
