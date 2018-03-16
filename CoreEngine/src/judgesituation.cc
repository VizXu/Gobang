#include "judgesituation.h"
#include <cstdlib>
#include <unistd.h>
#include <memory.h>

int Info::get_xpos() const
{
   return this->x_pos;
};

int Info::get_ypos() const
{
   return this->y_pos;
};

int Info::get_direction() const
{
   return this->direction;
};

void Info::set_xpos(int xpos)
{
   this->x_pos = xpos;
};

void Info::set_ypos(int ypos) 
{
   this->y_pos = ypos;
};

void Info::set_direction(int direction)
{
   this->direction = direction;
};

const Info& Info::operator()(int _x = 0, int _y = 0, int _d = 0)
{
   return std::move(Info(_x,_y,_d));
}

void Info::set(int xpos, int ypos, int direction)
{
   this->set_xpos(xpos);
   this->set_ypos(ypos);
   this->set_direction(direction);
}

bool Info::operator==(const Info& info)
{
   return this->x_pos == info.get_xpos() && this->y_pos == info.get_ypos() && this->direction == info.get_direction();
}

Chessmen_info::Chessmen_info()
{
   memset(chessmen_of_each_direction,0,sizeof(chessmen_of_each_direction));
   for(int i = 0; i < BOARD_SIZE*BOARD_SIZE; i++){
	ihas_won[i] = new Info();
	ilive4[i] = new Info();
	ilive4heap[i] = new Info();
	ilive3[i] = new Info();
	isleep3[i] = new Info();
	ilive2[i] = new Info();
	isleep2[i] = new Info();
   }
}

Chessmen_info::~Chessmen_info()
{
   for(int i = 0; i < BOARD_SIZE*BOARD_SIZE; i++){
	delete ihas_won[i];
	delete ilive4[i];
	delete ilive4heap[i];
	delete ilive3[i];
	delete isleep3[i];
	delete ilive2[i];
	delete isleep2[i];
   }
}

JudgeWin::JudgeWin()
{
  this->be_won = false;
  this->winner = '+';
  for(int i = 0;i < BOARD_SIZE; i++){
      for(int j = 0; j < BOARD_SIZE; j++){
            this->board_for_judge[i][j]= '+';
	 for(int k = 0 ; k < 8; k++){
	    this->judge_panel[i][j][k] = 0;
	 }
      }
  }
}

JudgeWin::~JudgeWin(){

}

void JudgeWin::copy_chessboard(const Chessboard& chessboard)
{
    for(int i = 0;i < BOARD_SIZE; i++){
      for(int j = 0; j < BOARD_SIZE; j++){
            this->board_for_judge[i][j]= chessboard.get_chess(i,j);
      }
    }
}

void JudgeWin::analysis_ilives(Chessmen_info* info, int level, int i, int j, int direction) const
{
	switch(level){
	   case IHAS_WON:info->ihas_won[i*BOARD_SIZE+j]->set(i,j,direction);break; 
	   case ILIVE4:info->ilive4[i*BOARD_SIZE+j]->set(i,j,direction);break; 
	   case ILIVE4HEAP:info->ilive4heap[i*BOARD_SIZE+j]->set(i,j,direction);break; 
	   case ILIVE3:info->ilive3[i*BOARD_SIZE+j]->set(i,j,direction);break; 
	   case ISLEEP3:info->isleep3[i*BOARD_SIZE+j]->set(i,j,direction);break; 
	   case ILIVE2:info->ilive2[i*BOARD_SIZE+j]->set(i,j,direction);break; 
	   case ISLEEP2:info->isleep2[i*BOARD_SIZE+j]->set(i,j,direction);break;
	   default:break; 
	}	
}

Chessmen_info* JudgeWin::scan_analysis_chessmen(char chessman) const
{
   int x_tmp;
   int y_tmp;
   int chessmen_of_each_direction[BOARD_SIZE][BOARD_SIZE][8] = { 0 };
   Chessmen_info* info = new Chessmen_info();

   for(int i = 0; i < BOARD_SIZE; i++){
	for(int j = 0; j < BOARD_SIZE; j++){
	    if(board_for_judge[i][j] == chessman){
		// -x direction(up)
		int k = 0;
		int p = 0;
		int q = 0;
		int r = 0;
		for(k = i; k >= 0; k--){
		   if(board_for_judge[k][j] == chessman) info->chessmen_of_each_direction[i][j][0] += 1;
		   else break;
		}

		switch(info->chessmen_of_each_direction[i][j][0]){
		   case 5:{
			this->analysis_ilives(info,IHAS_WON,i,j,0);
		   }
		   break;
		   case 4:{
			this->analysis_ilives(info,ILIVE4,i,j,0);
		   }
		   break;
		   case 3:{
			p = k - 1;
			if(p >= 0 && board_for_judge[p][j] == chessman){
				this->analysis_ilives(info,ILIVE4HEAP,i,j,0);
			}

			this->analysis_ilives(info,ILIVE3,i,j,0);
		   }
		   break;
		   case 2:{
			p = k -1;
			q = k -2;
			if(p >= 0 && board_for_judge[p][j] == chessman){
			   if(q >= 0 && board_for_judge[q][j] == chessman){
				this->analysis_ilives(info,ILIVE4HEAP,i,j,0);
			   }
			   else{
				this->analysis_ilives(info,ISLEEP3,i,j,0);
			   }
			}
			this->analysis_ilives(info,ILIVE2,i,j,0);
		   }
		   break;
		   case 1:{
			p = k -1;
			q = k -2;
			r = k -3;	
		   }
		   break;
		   default:break;
		}

		// +y direction(right)
                for(k = j; k < BOARD_SIZE; k++){
                   if(board_for_judge[i][k] == chessman) chessmen_of_each_direction[i][j][1] += 1;
                   else break;
                }
		// +x direction(down)
                for(k = i; k < BOARD_SIZE; k++){
                   if(board_for_judge[k][j] == chessman) chessmen_of_each_direction[i][j][2] += 1;
                   else break;
                }
		// -y direction(left)
                for(k = j; k >= 0; k--){
                   if(board_for_judge[i][j] == chessman) chessmen_of_each_direction[i][j][3] += 1;
                   else break;
                }
		// -x|+y direction(up|right)
                for(x_tmp = i, y_tmp = j; x_tmp >= 0 && y_tmp < BOARD_SIZE; x_tmp--,y_tmp++){
                   if(board_for_judge[x_tmp][y_tmp] == chessman) chessmen_of_each_direction[i][j][4] += 1;
                   else break;
                }
		// +x|+y direction(right|down)
                for(x_tmp = i, y_tmp = j; x_tmp < BOARD_SIZE && y_tmp < BOARD_SIZE; x_tmp++,y_tmp++){
                   if(board_for_judge[x_tmp][y_tmp] == chessman) chessmen_of_each_direction[i][j][5] += 1;
                   else break;
                }
		// -y|+x direction(left|down)
                for(x_tmp = i, y_tmp = j; x_tmp < BOARD_SIZE && y_tmp > 0; x_tmp++,y_tmp--){
                   if(board_for_judge[x_tmp][y_tmp] == chessman) chessmen_of_each_direction[i][j][6] += 1;
                   else break;
                }
		// -x|-y direction(left|up) 
                for(x_tmp = i, y_tmp = j; x_tmp >= 0 && y_tmp >= 0; x_tmp--,y_tmp--){
                   if(board_for_judge[x_tmp][y_tmp] == chessman) chessmen_of_each_direction[i][j][7] += 1;
                   else break;
                }
	    }
	    else{
		continue;
	    }
	}
   }
return info;
}

bool JudgeWin::won_the_game(char chessman) const
{
   //judge analysis

return true;
}

char JudgeWin::whois_winner() const
{
   if(be_won) return this->winner;
   return '+';
}
