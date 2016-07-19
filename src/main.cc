#include<iostream>
#include"chessBoard.h"
#include"person.h"
using std::cout;
using std::endl;
int run();
int main()
{
  try{
    run();
  }catch(const char* e)
  {
    cout<<e<<endl;
  }
return 0;
}
