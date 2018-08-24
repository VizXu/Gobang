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
	      for(int i = 0; i <= num; i++){
	          line_dst[k++] = board[i][num - i];
	      }
	      for(int i = num + 1; i < BOARD_SIZE; i++){
	   	   line_dst[k++] = '%';
	      }
	   }
	   else{
	      k = 0;
	      for(int i = 0 ; i < 2*BOARD_SIZE - num - 1; i++){
		   line_dst[k++] = board[num - BOARD_SIZE + 1 + i][BOARD_SIZE - i - 1];
	      }
	      for(int i = 2*BOARD_SIZE - num - 1; i < BOARD_SIZE; i++){
		   line_dst[k++] = '%';
	      }
	   }
	break;
	   if(num < 15){
	      k = 0;
	      for(int i = 0; i <= num; i++){
	          line_dst[k++] = board[BOARD_SIZE - num - 1 + i][i];
	      }
	      for(int i = num + 1; i < BOARD_SIZE; i++){
	   	   line_dst[k++] = '%';
	      }
	   }
	   else{
	      k = 0;
	      for(int i = 0 ; i < 2*BOARD_SIZE - num - 1; i++){
		   line_dst[k++] = board[i][num - BOARD_SIZE + 1 + i];
	      }
	      for(int i = 2*BOARD_SIZE - num - 1; i < BOARD_SIZE; i++){
		   line_dst[k++] = '%';
	      }
	   }
	break;
   }
}

void Evaluate::board_to_line()
{
   for(int i = 0; i < LINE_NUM; i++){
     this->copy_a_line(this->hline[i],this->whole_board,i,DIR::HDIR); 
     this->copy_a_line(this->vline[i],this->whole_board,i,DIR::VDIR); 
   }
   for(int i = 0; i < XLINE_NUM; i++){
     this->copy_a_line(this->rline[i],this->whole_board,i,DIR::RDIR);
     this->copy_a_line(this->lline[i],this->whole_board,i,DIR::LDIR);
   }
}

#ifdef DEBUG_ALPHA
void Evaluate::dis_lines(s8 lines[][BOARD_SIZE],int num,DIR dir)
{

}
#endif

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
