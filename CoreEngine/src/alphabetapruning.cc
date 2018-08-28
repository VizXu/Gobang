#include "alphabetapruning.h"

Evaluate::Evaluate()
{
   for(int i = 0; i < BOARD_SIZE; i++){
       for(int j = 0; j < BOARD_SIZE; j++){
	  this->whole_board[i][j] = '+';
       }
   }
   for(int i = 0; i < LINE_NUM; i++){
       for(int j = 0; j < BOARD_SIZE; j++){
	  this->hline[i][j] = '+';
	  this->vline[i][j] = '+';
       }
   }

   for(int i = 0; i < XLINE_NUM; i++){
       for(int j = 0; j < BOARD_SIZE; j++){
	  this->rline[i][j] = '+';
	  this->lline[i][j] = '+';
       }
   }
  
   this->lineAnalysis = new Analysisline();
}

Evaluate::~Evaluate()
{
   delete this->lineAnalysis;
}

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
	case LDIR:
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
  switch(dir){
     case HDIR:printf("the hline[%d]:",num);break;
     case VDIR:printf("the vline[%d]:",num);break;
     case RDIR:printf("the rline[%d]:",num);break;
     case LDIR:printf("the lline[%d]:",num);break;
  }
  for(int i = 0; i < BOARD_SIZE; i++){
     printf(" %c",lines[num][i]);
  }
}
void Evaluate::dis_a_line(LINE& line)
{
   printf("line: ");
   for(int i = 0; i < BOARD_SIZE; i++){
	printf("%c ",line[i]);
   }
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

void Evaluate::line_to_line(LINE& line1,s8 line2[BOARD_SIZE])
{
   for(int i = 0; i < BOARD_SIZE; i++){
      line1[i] = line2[i];
   }
}

void Evaluate::get_a_line(LINE& line,int num, DIR dir)
{
   switch(dir){
      case HDIR: line_to_line(line,this->hline[num]);break; 
      case VDIR: line_to_line(line,this->vline[num]);break; 
      case RDIR: line_to_line(line,this->rline[num]);break; 
      case LDIR: line_to_line(line,this->lline[num]);break; 
   }
return;
}

Analysisline::Analysisline()
{
   for(int i = 0; i < LINE_SIZE; i++){
      this->a_line[i] = '+';
   }
    this->FIVE = 0;
    this->FOUR = 0;
    this->GFOUR = 0;
    this->GFOUR = 0;
    this->THREE = 0;
    this->GTHREE = 0;
    this->TWO   = 0;
    this->GTWO  = 0;
    this->ONE   = 0;
}

Analysisline::~Analysisline()
{

}

void Analysisline::loadaLine(LINE& line)
{
    for(int i = 0; i < BOARD_SIZE; i++){
	this->a_line[i] = line[i];
	this->analyzed[i] = false;
    }
return;
}

void Analysisline::playerIs(char _player)
{
   this->player = _player;
   if(_player == '@'){
	this->enemy_player = '&';
   }
   else{
	this->enemy_player = '@';
   }
}

char Analysisline::enemy(char _player)
{
   if(_player == '@'){
	return '&';
   }
   else{ 
        return '@';
   }
}

int Analysisline::scores_of_line(char player)
{
   int score = 0;
   std::list<char> line_chess;
   int lpos = 0;
   int rpos = 0;
   int joinedChess = 0;

   for(int i = 0; !this->analyzed[i] and i < LINE_SIZE; i++){
	if(this->a_line[i] == player){
	   lpos = i;
	   joinedChess = 1;
	}
	else if(this->a_line[i] == this->enemy(player)){
	   for(int k = 0; k <= i; k++){
	      this->analyzed[k] = true;
	   }
	   continue;
	}
	else{
	   continue;
	}
	for(int j = i; j < LINE_SIZE; j++){
	   if(this->a_line[j] == player){
	      rpos = j;
	      joinedChess += 1;	
	   }
        }

	if(joinedChess == 5){
	   this->FIVE += 1;
	   for(int l = lpos; l <= rpos; l++){
	      this->analyzed[l] = true;
	   }
	}
	if(joinedChess == 4){
	   
	}
	if(joinedChess == 3){
	   
	}
	if(joinedChess == 2){
	   
	}
	if(joinedChess == 1){
	   
	}
   }
return score;
}

AlphaBetaPruning::AlphaBetaPruning()
{
   for(int i = 0; i < BOARD_SIZE; i++){
      for(int j = 0; j < BOARD_SIZE; j++){
	 this->board_for_pruning[i][j] = '+';	
      }
   }
   evaluate = new Evaluate();
}
AlphaBetaPruning::~AlphaBetaPruning()
{
   delete evaluate;
}

void AlphaBetaPruning::display_line_info()
{
    LINE line;
    this->evaluate->board_to_line();
    this->evaluate->get_a_line(line,15,LDIR);
    this->evaluate->dis_a_line(line);
}

void AlphaBetaPruning::loadBoard(const Chessboard& board)
{
   for(int i = 0;i < BOARD_SIZE; i++){
        for(int j = 0; j < BOARD_SIZE; j++){
           this->board_for_pruning[i][j]= board.get_chess(i,j);
 	}
   }
   evaluate->copy_from_board(this->board_for_pruning);
}
