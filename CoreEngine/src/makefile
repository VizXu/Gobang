
obj = test.o ai_core.o chessboard.o player.o computer.o human.o \
	testwinner.o

CXX = g++
parameters = -std=c++0x

gobang: $(obj)
	$(CXX) $(obj) -o gobang $(parameters)
	@echo "good,gobang compile done"

player.o : $^
	$(CXX) -c player.cc -o $@ $(parameters)
	@echo "player.cc compile"

test.o : test.cc types.h debug.h computer.h
	$(CXX) -c test.cc -o test.o $(parameters)
	@echo "test.cc compile"

ai_core.o : ai_core.cc types.h debug.h boardposition.h
	$(CXX) -c ai_core.cc -o ai_core.o $(parameters)
	@echo "ai_core.cc compile"

computer.o : $^
	$(CXX) -c computer.cc -o $@ $(parameters)
	@echo "computer.cc compile"

human.o : $^
	$(CXX) -c human.cc -o $@ $(parameters)
	@echo "human.cc compile"

chessboard.o : chessboard.cc chessboard.h
	$(CXX) -c chessboard.cc -o chessboard.o $(parameters)
	@echo "chessboard.cc compile"

testwinner.o : $^
	$(CXX) -c testwinner.cc -o $@ $(parameters)
	@echo "testwinner.cc compile"
install:

uninstall:
	rm -rf ./gobang

## clean the .o files
clean:
	rm -rf ./*.o
