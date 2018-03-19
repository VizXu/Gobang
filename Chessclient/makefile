
CXX=g++

parameters=-std=c++11


ChessClient: client.o
	$(CXX) client.o -o $@

client.o : client.cc
	$(CXX) -c client.cc -o $@

clean:
	rm ./*.o 
	rm ChessClient
