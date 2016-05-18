#ifndef _PLAYER_
#define _PLAYER_
#include<stirng>
using std::string;
class Player
{
private:
   int gold;
   string name;
private:
   
public：
   string getName()
   {
      return this->name;
   }
   int getGold()
   {
      return this->gold;
   }
};
#endif//player.h
