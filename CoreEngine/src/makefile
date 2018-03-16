
obj = test.o ai_core.o chessboard.o player.o computer.o human.o \
	testwinner.o storechessmanual.o chessboardinfo.o \
	judgesituation.o display.o
#	add.o

INPUT = yes

OBJ_DIR = objs_dir/

INPUT_DIR = input/

target = target_dir/

inc = headers

CXX = g++

parameters = -std=c++11

ifeq ($(INPUT),yes)
#obj += add.o
endif

gobang: $(obj)
	$(CXX) $(OBJ_DIR)*.o -o $(target)gobang $(parameters)
#	@echo "good,gobang compile done"

display.o : display.cc
	$(CXX) -c display.cc -o $(OBJ_DIR)display.o $(parameters) -I$(inc)
#	@echo "display.cc compile"

player.o : player.cc
	$(CXX) -c player.cc -o $(OBJ_DIR)player.o $(parameters) -I$(inc)
#	@echo "player.cc compile"

judgesituation.o : judgesituation.cc
	$(CXX) -c judgesituation.cc -o $(OBJ_DIR)judgesituation.o $(parameters) -I$(inc)
	@echo "judgesituation.cc compile"

test.o : test.cc
	$(CXX) -c test.cc -o $(OBJ_DIR)test.o $(parameters) -I$(inc)
#	@echo "test.cc compile"

ai_core.o : ai_core.cc
	$(CXX) -c ai_core.cc -o $(OBJ_DIR)ai_core.o $(parameters) -I$(inc)
#	@echo "ai_core.cc compile"

computer.o : computer.cc
	$(CXX) -c computer.cc -o $(OBJ_DIR)computer.o $(parameters) -I$(inc)
#	@echo "computer.cc compile"

human.o : human.cc
	$(CXX) -c human.cc -o $(OBJ_DIR)human.o $(parameters) -I$(inc)
#	@echo "human.cc compile"

chessboard.o : chessboard.cc
	$(CXX) -c chessboard.cc -o $(OBJ_DIR)chessboard.o $(parameters) -I$(inc)
#	@echo "chessboard.cc compile"

testwinner.o : testwinner.cc
	$(CXX) -c testwinner.cc -o $(OBJ_DIR)testwinner.o $(parameters) -I$(inc)
#	@echo "testwinner.cc compile"

storechessmanual.o : storechessmanual.cc
	$(CXX) -c storechessmanual.cc -o $(OBJ_DIR)storechessmanual.o $(parameters) -I$(inc)
#	@echo "storechessmanual.cc compile"

chessboardinfo.o : chessboardinfo.cc
	$(CXX) -c chessboardinfo.cc -o $(OBJ_DIR)chessboardinfo.o $(parameters) -I$(inc)
#	@echo "chessboardinfo.cc compile"
#ifeq ($(INPUT),yes)
add.o:	add.cc
	$(CXX) -c $(INPUT_DIR)add.cc -o $(OBJ_DIR)add.o $(parameters) -I$(inc)
#	@echo "hahhhhah"
#endif

install:

uninstall:
	rm -rf $(target)gobang

## clean the .o files
clean:
	rm -rf $(OBJ_DIR)*.o
