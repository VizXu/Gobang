
OBJ= computer.o chessBoard.o chessmaninfo.o \
	 person.o player.o run.o handleChess.o \
	 test.o main.o
# clean is to remove .o files
.PHONY:clean
.PHONY:install
.PHONY:uninstall

#CXX stands for g++

CXX=g++

PARAMETER=-std=c++11

Gobang: $(OBJ)
	$(CXX)  *.o -o Gobang
computer.o: computer.cc 
	$(CXX) $(PARAMETER) -c computer.cc -o computer.o
chessBoard.o: chessBoard.cc 
	$(CXX) $(PARAMETER) -c chessBoard.cc -o chessBoard.o
chessmaninfo.o: chessmaninfo.cc
	$(CXX) $(PARAMETER) -c chessmaninfo.cc -o chessmaninfo.o
person.o: person.cc 
	$(CXX) $(PARAMETER) -c person.cc -o person.o
player.o: player.cc 
	$(CXX) $(PARAMETER) -c player.cc -o player.o
run.o: run.cc
	$(CXX) $(PARAMETER) -c run.cc -o run.o
handleChess.o: handleChess.cc 
	$(CXX) $(PARAMETER) -c handleChess.cc -o handleChess.o
test.o:test.cc
	$(CXX) $(PARAMETER) -c test.cc -o test.o
main.o: main.cc
	$(CXX) $(PARAMETER) -c main.cc -o main.o
clean:
	rm ./*.o
install:

uninstall:
