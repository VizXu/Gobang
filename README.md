# Gobang 

Gobang is an athletic chess game, which players can set chessman in an empty site of chessboard each other step by step and one wins the game until he has five chessman connected that being a line. 

As a coding-lover and AI-lover,I wrote the Gobang with C++,which runs in Linux platform.The game uses the characters interface because I just only wanna develop an AI engine program. One who is tending to 
develop GUI with Qt or other tools can use these codes as algorithm.

In the recent years,huge process has been made in AI domin, but most gobang AI based on rules strategy,which is not "real" AI that has self-learning ability.So I wanna try to develop a core AI engine so that one can use it as a gobang AI algorithm. 

These codes run on the Ubuntu or other linux OS,one can download the source code and compile with **"make"** instruction.Anyone has the authority to download the source code and modify it,but I also do not take the responsibility to any lost made by the code.

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
