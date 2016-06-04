#ifndef _COMPUTER_
#define _COMPUTER_
#include"player.h"
#include<string>
typedef unsigned int U32;
class Computer:public Player
{
private:
  U32 levels;
  string name;
public:
  string getName();
  U32 getLevel();
};
#endif//computer.h
