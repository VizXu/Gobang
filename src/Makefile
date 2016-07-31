Gobang: computer.o chessBoard.o chessmaninfo.o \
	    person.o player.o run.o handleChess.o \
		main.o
	g++  *.o -o Gobang
computer.o: computer.cc 
	g++ -std=c++11 -c computer.cc -o computer.o
chessBoard.o: chessBoard.cc 
	g++ -std=c++11 -c chessBoard.cc -o chessBoard.o
chessmaninfo.o: chessmaninfo.cc
	g++ -std=c++11 -c chessmaninfo.cc -o chessmaninfo.o
person.o: person.cc 
	g++ -std=c++11 -c person.cc -o person.o
player.o: player.cc 
	g++ -std=c++11 -c player.cc -o player.o
run.o: run.cc
	g++ -std=c++11 -c run.cc -o run.o
handleChess.o: handleChess.cc 
	g++ -std=c++11 -c handleChess.cc -o handleChess.o
main.o: main.cc
	g++ -std=c++11 -c main.cc -o main.o
clean:
	rm ./*.o
install:

uninstall:
