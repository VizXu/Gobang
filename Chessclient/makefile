obj = client.o run.o

CXX=g++

parameters=-std=c++11


ChessClient: $(obj)
	$(CXX) $^ -o $@

client.o : client.cc
	$(CXX) -c client.cc -o $@

run.o : run.cc
	$(CXX) -c run.cc -o $@

clean:
	rm ./*.o 
	rm ChessClient

install:
	cp ./ChessClient /usr/bin
