# Gobang Introduction 

Gobang is an athletic chess game, which players can set chessman in an empty site of chessboard each other step by step and one wins the game until he has five chessman connected that being a line. 

In the recent years,huge process has been made in AI domain, but most gobang AI based on rules strategy,which is not "real" AI that has self-learning ability.So I wanna try to develop a core AI engine so that one can use it as a gobang AI algorithm. 

As a coding-lover and AI-lover,I use spare time to develop a gobang game AI engine with C++,which runs in Linux platform.The architecture of source code is based on client-server model. Gobang AI is a daemon server and client connect the server with specific format to set chessman or get chessboard information from server, the client could be called by Qt, Python UI or other UI libs or tools, so one who is tending to develop GUI Gobang Game can use these codes as core engine.

The server codes is in GobangGame/CoreEngine/src/ and client code is in GobangGame/CoreEngine/Client/, one can download the source code and compile with **"make"** instruction. The client side is developed by character interface runs ubuntu OS, GUI developing can use these codes. Anyone has the authority to download the source code and modify it,but I also do not take the responsibility to any lost made by the code.


---
##### 2016-8 to 2017-7

- add level 2 AI algorithm 

- released the first version 0.1

- reconsitute the code

- move the core code to CoreEngine directory, one can enter the CoreEngine and compile
  the source code with "make"

- upload the arch image

![arch image](https://github.com/VizXu/GobangGame/blob/master/CoreEngine/src/img/arch.png)

- update module of chess manual reservation

- add eveluation function method to update AI 

- add the autoconf tools

##### 2017-8 to 2018-4
- add UI

## How to use it

-compile

	I.   compile CoreEngine
		cd ~/CoreEngine/src/ && make
![coreengine image](https://github.com/VizXu/GobangGame/blob/master/CoreEngine/src/img/1.png)

	II.  compile Chessclient
		cd ~/Chessclient/ && make
![coreengine image](https://github.com/VizXu/GobangGame/blob/master/CoreEngine/src/img/3.png)

	III. compile UI
		cd ~/UI/ && qmake && make

-usage

	I.   run gobang daemon
![coreengine image](https://github.com/VizXu/GobangGame/blob/master/CoreEngine/src/img/2.png)

	II.  cp ChessClient to /usr/bin
![coreengine image](https://github.com/VizXu/GobangGame/blob/master/CoreEngine/src/img/4.png)

	III. start the game, first select level to be 1 and push the "Start game" button
![coreengine image](https://github.com/VizXu/GobangGame/blob/master/CoreEngine/src/img/7.png)
![coreengine image](https://github.com/VizXu/GobangGame/blob/master/CoreEngine/src/img/8.png)


