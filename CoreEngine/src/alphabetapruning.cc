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

int Evaluate::score_of_aline(char player,int num,DIR dir)
{
    LINE line;
    this->get_a_line(line,num,dir);
    this->lineAnalysis->loadaLine(line);
return  this->lineAnalysis->scores_of_line(player);
}

int Evaluate::scores_of_players(char player)
{
   return this->score_of_aline(player,12,DIR::HDIR);
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

   printf("\nplayer = %c\n",player);
   printf("this->a_line = ");
   for(int n = 0; n < LINE_SIZE; n++){
	printf("%c ",this->a_line[n]);
   }
   printf("\nthis->analyzed = ");
   for(int n = 0; n < LINE_SIZE; n++){
	printf("%d ",this->analyzed[n]);
   }

   for(int i = 0; !this->analyzed[i] and i < LINE_SIZE and this->a_line[i] != '%'; i++){
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
	for(int j = i + 1; j < LINE_SIZE; j++){
	   if(this->a_line[j] == player){
	      rpos = j;
	      joinedChess += 1;	
	   }
	   else break;
        }

	if(joinedChess == 5){
	   this->FIVE += 1;
	   for(int l = lpos; l <= rpos; l++){
	      this->analyzed[l] = true;
	      printf("\nenter five, l = %d\n",l);
	   }
	}
	else if(joinedChess == 4){
	   if(lpos - 1 >= 0 and this->a_line[lpos - 1] == '+'){
		if(rpos + 1 < LINE_SIZE and this->a_line[rpos + 1] == '+'){
	   	   this->FOUR += 1;
		   for(int p = lpos - 1; p <= rpos + 1; p++){
		      this->analyzed[p] = true;
		   }
		}
		//else if(rpos + 1 < LINE_SIZE; and this->a_line[rpos + 1] == this->enemy(player)){
		else{
		   this->GFOUR += 1;
		   for(int p = lpos - 1; p < LINE_SIZE and p <= rpos + 1; p++){
		      this->analyzed[p] = true;
		   }
		}
	   }
	   else{
		if(rpos + 1 < LINE_SIZE and this->a_line[rpos + 1] == '+'){
	   	   this->GFOUR += 1;
		   for(int p = lpos - 1; p <= rpos + 1; p++){
		      this->analyzed[p] = true;
		   }
		}
		else{
		   for(int p = lpos - 1; p < LINE_SIZE and p <= rpos + 1; p++){
		      this->analyzed[p] = true;
		   }
		}
	   }
	}
	else if(joinedChess == 3){
	   int l_bandary = lpos;
	   int r_bandary = rpos;
	   
	   if(l_bandary - 2 >=0){
		if(this->a_line[l_bandary - 2] == player){
		  if(this->a_line[l_bandary - 1] == '+'){
		     if(r_bandary + 1 < LINE_SIZE and this->a_line[r_bandary + 1] == '+'){
		         if(r_bandary + 2 < LINE_SIZE and this->a_line[r_bandary + 2] == player){
			    this->GTHREE += 1;
		         }
		         else{
			    this->THREE += 1;
		         }
		      }
		      else{
		         this->THREE += 1;
		      }
		   }
		   else if(this->a_line[l_bandary - 1] == this->enemy(player)){
		     if(r_bandary + 1 < LINE_SIZE and this->a_line[r_bandary + 1] == '+'){
		         if(r_bandary + 2 < LINE_SIZE and this->a_line[r_bandary + 2] == player){
			    this->THREE += 1;
		         }
		         else if(r_bandary + 2 < LINE_SIZE and this->a_line[r_bandary + 2] == '+'){
			    this->GTHREE += 1;
		         }
		      }
		   }
	        }
		else if(this->a_line[l_bandary - 2] == '+'){
		   if(this->a_line[l_bandary - 1] == '+'){
			
		   }
		   else if(this->a_line[l_bandary - 1] == this->enemy(player)){

		   }
		}
		else{
		   
		}
	   }
	}
	else if(joinedChess == 2){
	       this->TWO += 1;
	}
	else if(joinedChess == 1){
		this->ONE += 1;       
	}
	
   }
	score += this->FIVE*9999;
	score += this->FOUR*9998;
	score += this->GFOUR*4999;
	score += this->THREE*2499;
	score += this->TWO*624;
	score += this->ONE*100;
	printf("\n---> score = %d\n",score);
   printf("\nafter ---> this->analyzed = ");
   for(int n = 0; n < LINE_SIZE; n++){
	printf("%d ",this->analyzed[n]);
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

int AlphaBetaPruning::boardScore(char player)
{
   this->evaluate->board_to_line();
   return this->evaluate->scores_of_players(player);
}
