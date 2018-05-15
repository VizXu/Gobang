#include"computer.h"
extern void display_chessboard(const Chessboard&);

Computer::Computer(string s):Player("computer"),computer_name(s),computer_chess_type('@')
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


s8 Computer::get_computer_chess_type()
{
  return this->computer_chess_type;
}

bool Computer::make_a_step(Chessboard& chessboard)
{
     s8 the_type = get_computer_chess_type();

//   if(this->move_state  == start){
	      u32 the_level = this->level;

	      this->ai_analysis(chessboard,the_level);
	      if(chessboard.set_chess(this->suggest_position.x_pos,this->suggest_position.y_pos,the_type)){
	         this->last_position = this->present_position;
		 	 this->present_position = this->suggest_position;
	      }
//    }
    else{
       return false;
    }
}

void Computer::ai_analysis(const Chessboard& chessboard,u32 level)
{
   this->ai->copy_board(chessboard);
   
   switch(level)
   {
     case 1:this->ai->analyze_level1('&');break;
     case 2:this->ai->analyze_level2(chessboard, '@');break;
     case 3:this->ai->analyze_level1('@');break;
     default:break;
   }

   //for test
   //ai->analyze_level2(chessboard, '@');
   //end
   
   this->suggest_position = this->ai->get_suggest_position();
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
