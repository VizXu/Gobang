#ifndef _COMPUTER_
#define _COMPUTER_
#include"player.h"
#include"types.h"
#include<cstdlib>
#include<string>
class Computer:public Player
{
private:
  U8 levels;
  string name;
public:
  Computer(string n="Computer"):name(n),Player(n){
    srand(time(NULL));
  }
  ~Computer(){}
public:
  string getName();
  U8 getLevel();
  void setLevel(U8 level);
};
#endif//computer.h
