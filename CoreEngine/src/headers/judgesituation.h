#ifndef _JUDGESITUATION_
#define _JUDGESITUATION_
#include "chessboard.h"

#define TOTALPOSSIZE BOARD_SIZE*BOARD_SIZE

#define ROTATE0   0
#define ROTATE90  2
#define ROTATE180 4
#define ROTATE270 6


const int IHAS_WON = 0;

/**********************
@IHAS_WON five chessman connect to be a line 

    | | | | |
  --&-&-&-&-&--
    | | | | |

**********************/

const int ILIVE4 = 1;

/**********************
@ILIVE4 has two position to become IHAS_WON

    | | | | 
  --&-&-&-&--
    | | | | 

**********************/

const int ILIVE4HEAP = 2;

/**********************
@ILIVE4HEAP has one position to become IHAS_WON

    | | | | |
  --@-&-&-&-&--
    | | | | |

    | | | | |
  --&-&---&-&--
    | | | | |
    
    | | | | |
  --&---&-&-&--
    | | | | |

**********************/

const int ILIVE3 = 3;

/**********************
@ILIVE3 can become ILIVE4

    | | | | |
  ----&-&-&----
    | | | | |
    
    | | | | |
  --&---&-&----
    | | | | |

**********************/

const int ISLEEP3 = 4;

/**********************
@ISLEEP3 can become ILIVE4HEAP

    | | | | |
  --@-&-&-&----
    | | | | |

    | | | | |
  --@-&-&---&--
    | | | | |
    
    | | | | |
  --@-&---&-&--
    | | | | |
        
    | | | | |
  --&-&-----&--
    | | | | |

    | | | | |
  --&---&---&--
    | | | | |
    	  
    | | | | | | |
  --@---&-&-&---@-
    | | | | | | |

**********************/

const int ILIVE2 = 5;

/**********************
@ILIVE2 can become ILIVE3

    | | | | |
  ----&-&------
    | | | | |

    | | | | |
  ----&---&----
    | | | | |
    
    | | | | |
  ----&-----&--
    | | | | |

**********************/

const int ISLEEP2 = 6;

/**********************
@ILIVE2 can become ISLEEP3

    | | | | |
  --@-&-&------
    | | | | |

    | | | | |
  --@-&---&----
    | | | | |
    
    | | | | |
  --@-&-----&--
    | | | | |
        
    | | | | |
  --&-------&--
    | | | | |

**********************/

class Info
{
private:
   int x_pos;
   int y_pos;
   int index;
   int direction;
public:
   Info(int _x = 0, int _y = 0, int _d = 0):x_pos(_x),y_pos(_y),direction(_d){}
   ~Info(){}
public:
   int get_xpos() const;
   int get_ypos() const;
   int get_direction() const;
   void set_xpos(int);
   void set_ypos(int);
   void set_index(int);
   void set_direction(int);
   const Info& operator()(int, int, int);
   void set(int,int,int);
   void set(int,int);
   bool operator==(const Info&);
};
class Chessmen_info
{
private:
public:
   int chessmen_of_each_direction[BOARD_SIZE][BOARD_SIZE][8];
   Info*   ihas_won[TOTALPOSSIZE];
   Info*   ilive4[TOTALPOSSIZE];
   Info*   ilive4heap[TOTALPOSSIZE];
   Info*   ilive3[TOTALPOSSIZE];
   Info*   isleep3[TOTALPOSSIZE];
   Info*   ilive2[TOTALPOSSIZE];
   Info*   isleep2[TOTALPOSSIZE];
   static int IHAS_WON;
   static int ILIVE4;
   static int ILIVE4HEAP;
   static int ILIVE3;
   static int ISLEEP3;
   static int ILIVE2;
   static int ISLEEP2;
public:
   Chessmen_info();
   ~Chessmen_info();
};

class JudgeWin
{
private:
   bool be_won;
   char winner;// should be '&' or '@'
   s8 board_for_judge[BOARD_SIZE][BOARD_SIZE];
   s8 each_direction_board_for_judge[BOARD_SIZE][BOARD_SIZE];
   int judge_panel[BOARD_SIZE][BOARD_SIZE][8];
public:
   JudgeWin();
   ~JudgeWin();
public:
   void copy_chessboard(const Chessboard&);
   char whois_winner() const;
private:
   int transferIndex(int,int,int);
   void rotate(int);
   void rotate0(s8 originBoard[][BOARD_SIZE]);
   void rotate90(s8 originBoard[][BOARD_SIZE]);
   void rotate180(s8 originBoard[][BOARD_SIZE]);
   void rotate270(s8 originBoard[][BOARD_SIZE]);

private:
   bool won_the_game(char) const;
   void analysis_for_each_direction(char chessman,s8 temp[][BOARD_SIZE],Chessmen_info* info,int rotate);
   void analysis_ilives(Chessmen_info*, int, int, int);
public:
   Chessmen_info* scan_analysis_chessmen(char);

};

class JudgeSituation
{
private:
   JudgeWin isWin;
public:
};

#endif//judgesituation.h
