#ifndef _COMPUTER_
#define _COMPUTER_
#include"player.h"
#include"chessBoard.h""
#include"types.h"
#include<cstdlib>
#include<string>
class Position
{
private:
  int _x;
  int _y;
public:
  Position(int x=0,int y=0):_x(x),_y(y){}
  ~Position(){}
public:
  int getX(){return _x;}
  int getY(){return _y;}
  void setXY(int x,int y){_x=x;_y=y;}
};
class Computer:public Player
{
private:
  U8 levels;
  string name;
  Position position;
public:
  Computer(string n="Computer"):name(n),Player(n){
    srand(time(NULL));
  }
  ~Computer(){}
public:
  string getName();
  U8 getLevel();
  void setLevel(U8 level);
public:
  Position level1();
  Position level2();
  Position level3();
  Position level4();
public:
  int setPos(ChessBoard&);
};
#endif//computer.h
