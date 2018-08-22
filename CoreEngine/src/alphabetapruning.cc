#include "alphabetapruning.h"

void Evaluate::copy_a_line(s8 line_dst[],s8 board[BOARD_SIZE][BOARD_SIZE], int num, DIR dir)
{
   int k = 0;
   switch(dir){
	case HDIR: 
	   for(int i = 0; i < BOARD_SIZE; i++){
	      line_dst[i] = board[num][i];	
	   }
	break;
	case VDIR:
	   for(int i = 0; i < BOARD_SIZE; i++){
	      line_dst[i] = board[i][num];
	   }
	case RDIR:
	   if(num < 15){
	      k = 0;
	      for(int i = 0; i < num; i++){
	          line_dst[k++] = board[i][num - i];
	      }
	      for(int i = num; i < BOARD_SIZE; i++){
	   	   line_dst[k++] = '%';
	      }
	   }
	   else{
	      k = 0;
	      for(int i = 0 ; i < num - BOARD_SIZE; i++){
		   line_dst[k++] = board[2*BOARD_SIZE - num + i][BOARD_SIZE - i];
	      }
	      for(int i = num - BOARD_SIZE; i < BOARD_SIZE; i++){
		   line_dst[k++] = '%';
	      }
	   }
	break;
	   k = 0;
	   for(int i = 0; i < num; i++){
	   }
   }
}

void Evaluate::board_to_line()
{
   for(int i = 0; i < LINE_NUM; i++){
     this->copy_a_line(this->hline[i],this->whole_board,i,DIR::HDIR); 
     this->copy_a_line(this->vline[i],this->whole_board,i,DIR::VDIR); 
   }
}

void Evaluate::copy_from_board(const s8 board[][BOARD_SIZE])
{
   for(int i = 0; i < BOARD_SIZE; i++){
      for(int j = 0; j < BOARD_SIZE; j++){
	 this->whole_board[i][j] = board[i][j];
      }
   }
}

void Analysisline::loadaLine(s8 * line)
{
return;
}

void AlphaBetaPruning::loadBoard(const Chessboard& board)
{
   for(int i = 0;i < BOARD_SIZE; i++){
        for(int j = 0; j < BOARD_SIZE; j++){
           this->board_for_pruning[i][j]= board.get_chess(i,j);
 	}
   }
}
