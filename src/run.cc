#include<iostream>
#include<string>
#include"person.h"
#include"computer.h"
using std::cout;
using std::endl;
using std::cin;
using std::string;
int run()
{
//start the game
  flag1:
  string playerName;
  string computName;
  cout<<"----start----"<<endl;
  cout<<"Please put in you name:"<<endl;
  cin>>playerName;
  if(!cin.good()){
    cout<<"Input error,Please put in again"<<endl;
    while(cin.get()!='\n')continue;
    goto flag1;
  }
}
