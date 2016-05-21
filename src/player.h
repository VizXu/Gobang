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
   string getName() const
   {
      return this->name;
   }
   int getGold() const
   {
      return this->gold;
   }
   void setPosition(int _x,int _y);
};
#endif//player.h
