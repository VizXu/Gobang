#ifndef _PERSON_
#define _PERSON_
#include<string>
#include"player.h"
using std::string;
class Person:public Player
{
private:
  string name;
public:
  Person(){}
  Person(string n="Zhangsan"):Player(n){}
  ~Person(){}
public:
  int play(int _x,int _y,char ch,ChessBoard& chessboard);
  string getName();
};
#endif//person.h
