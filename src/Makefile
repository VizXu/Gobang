
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
	$(CXX)  $(OBJ) -o Gobang
	@echo "successful"
computer.o: computer.cc 
	$(CXX) $(PARAMETER) -c computer.cc -o computer.o
	@echo "computer.o is done"
chessBoard.o: chessBoard.cc 
	$(CXX) $(PARAMETER) -c chessBoard.cc -o chessBoard.o
	@echo "chessBoard.o is done"
chessmaninfo.o: chessmaninfo.cc
	$(CXX) $(PARAMETER) -c chessmaninfo.cc -o chessmaninfo.o
	@echo "chessmaninfo.o is done"
person.o: person.cc 
	$(CXX) $(PARAMETER) -c person.cc -o person.o
	@echo "person.o is done"
player.o: player.cc 
	$(CXX) $(PARAMETER) -c player.cc -o player.o
	@echo "player.o is done"
run.o: run.cc
	$(CXX) $(PARAMETER) -c run.cc -o run.o
	@echo "run.o is done"
handleChess.o: handleChess.cc 
	$(CXX) $(PARAMETER) -c handleChess.cc -o handleChess.o
	@echo "handleChess.o is done"
test.o:test.cc
	$(CXX) $(PARAMETER) -c test.cc -o test.o
	@echo "test.o is done"
main.o: main.cc
	$(CXX) $(PARAMETER) -c main.cc -o main.o
	@echo "main.o is done"
clean:
	rm ./*.o
install:

uninstall:
