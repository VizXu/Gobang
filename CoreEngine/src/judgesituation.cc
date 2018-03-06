#include "judgesituation.h"

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

bool JudgeWin::won_the_game(char chessman) const
{
   //judge analysis
   int x_tmp;
   int y_tmp;
   int chessmen_of_each_direction[BOARD_SIZE][BOARD_SIZE][8] = { 0 };

   for(int i = 0; i < BOARD_SIZE; i++){
	for(int j = 0; j < BOARD_SIZE; j++){
	    if(board_for_judge[i][j] == chessman){
		// -x direction(up)
		for(int k = i; k >= 0; k--){
		   if(board_for_judge[k][j] == chessman) chessmen_of_each_direction[i][j][0] += 1;
		   else break;
		}
		// +y direction(right)
                for(int k = j; k < BOARD_SIZE; k++){
                   if(board_for_judge[i][k] == chessman) chessmen_of_each_direction[i][j][1] += 1;
                   else break;
                }
		// +x direction(down)
                for(int k = i; k < BOARD_SIZE; k++){
                   if(board_for_judge[k][j] == chessman) chessmen_of_each_direction[i][j][2] += 1;
                   else break;
                }
		// -y direction(left)
                for(int k = j; k >= 0; k--){
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
return true;
}

char JudgeWin::whois_winner() const
{
   if(be_won) return this->winner;
   return '+';
}
