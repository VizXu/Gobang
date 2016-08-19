
OBJ= computer.o chessBoard.o chessmaninfo.o \
	 person.o player.o run.o handleChess.o \
	 test.o main.o
# clean is to remove .o files
.PHONY:clean
PARAMETER=-std=c++11

Gobang: $(OBJ)
	g++  *.o -o Gobang
computer.o: computer.cc 
	g++ $(PARAMETER) -c computer.cc -o computer.o
chessBoard.o: chessBoard.cc 
	g++ $(PARAMETER) -c chessBoard.cc -o chessBoard.o
chessmaninfo.o: chessmaninfo.cc
	g++ $(PARAMETER) -c chessmaninfo.cc -o chessmaninfo.o
person.o: person.cc 
	g++ $(PARAMETER) -c person.cc -o person.o
player.o: player.cc 
	g++ $(PARAMETER) -c player.cc -o player.o
run.o: run.cc
	g++ $(PARAMETER) -c run.cc -o run.o
handleChess.o: handleChess.cc 
	g++ $(PARAMETER) -c handleChess.cc -o handleChess.o
test.o:test.cc
	g++ $(PARAMETER) -c test.cc -o test.o
main.o: main.cc
	g++ $(PARAMETER) -c main.cc -o main.o
clean:
	rm ./*.o
install:

uninstall:
