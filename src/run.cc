#include<iostream>
#include<string>
#include<unistd.h>
#include"person.h"
#include"computer.h"
#include"chessBoard.h"
#include"types.h"
using std::cout;
using std::endl;
using std::cin;
using std::string;
int run()
{
//start the game
  string playerName;
  string computName;
  cout<<"----start----"<<endl;
  flag1:
  cout<<"Please put in you name:"<<endl;
  cin>>playerName;
  if(!cin.good()){
    cout<<"Input error,Please put in again"<<endl;
    cin.clear();
    while(cin.get()!='\n')continue;
    goto flag1;
  }
  flag2:
  cout<<"Please put in the computer's name:"<<endl;
  cin>>computName;
  if(!cin.good()){
    cout<<"Input error,Please put in again"<<endl;
    cin.clear();
    while(cin.get()!='\n')continue;
    goto flag2;
  }
  cout<<"Good,start the chess..."<<endl;
  ChessBoard chessboard;
  Person person(playerName);
  Computer computer(computName);
  U8 difcltDgr=0;
  cout<<"Please chose the difficulty of the game(1,2,3 or 4):"<<endl;
  flag3:
    cin>>difcltDgr;
    if(!cin.good()){
      cout<<"Please chose the right difficulty!"<<endl;
      cin.clear();
      while(cin.get()!='\n')continue;
      goto flag3;
    }
    cout<<"Good,you have chose the level "<<difcltDgr<<" of the game,good luck!"<<endl;
    computer.setLevel(difcltDgr);
	int xPosition;
	int yPosition;
	while(true){
		cout<<"game is starting..."<<endl;
		chessboard.displayChessBoard();
	flag4:
		cout<<"Please put a chessman:"<<endl;
		cin>>xPosition>>yPosition;
		if(!cin.good()){
			cout<<"put error!"<<endl;
			cin.clear();
			while(cin.get()!='\n')continue;
			goto flag4;
		}
		while(true){
			if(!person.play(xPosition,yPosition,'#',chessboard))break;
			else goto flag4;
		}
		chessboard.displayChessBoard();
	flag5:
		system("clear");
		cout<<"computer put chessman..."<<endl;
		while(true){
			if(!computer.setPos(chessboard))break;
			else continue;
		}
		chessboard.displayChessBoard();
	}
}
