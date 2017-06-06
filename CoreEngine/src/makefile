
obj = test.o ai_core.o chessboard.o player.o computer.o human.o \
	testwinner.o

OBJ_DIR = objs_dir/

target = target_dir/

CXX = g++

parameters = -std=c++11

gobang: $(obj)
	$(CXX) $(OBJ_DIR)*.o -o $(target)gobang $(parameters)
	@echo "good,gobang compile done"

player.o : player.cc
	$(CXX) -c player.cc -o $(OBJ_DIR)player.o $(parameters)
	@echo "player.cc compile"

test.o : test.cc
	$(CXX) -c test.cc -o $(OBJ_DIR)test.o $(parameters)
	@echo "test.cc compile"

ai_core.o : ai_core.cc
	$(CXX) -c ai_core.cc -o $(OBJ_DIR)ai_core.o $(parameters)
	@echo "ai_core.cc compile"

computer.o : computer.cc
	$(CXX) -c computer.cc -o $(OBJ_DIR)computer.o $(parameters)
	@echo "computer.cc compile"

human.o : human.cc
	$(CXX) -c human.cc -o $(OBJ_DIR)human.o $(parameters)
	@echo "human.cc compile"

chessboard.o : chessboard.cc
	$(CXX) -c chessboard.cc -o $(OBJ_DIR)chessboard.o $(parameters)
	@echo "chessboard.cc compile"

testwinner.o : testwinner.cc
	$(CXX) -c testwinner.cc -o $(OBJ_DIR)testwinner.o $(parameters)
	@echo "testwinner.cc compile"
install:

uninstall:
	rm -rf $(target)gobang

## clean the .o files
clean:
	rm -rf $(OBJ_DIR)*.o
