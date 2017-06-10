#ifndef _STORE_CHESS_MENUAL_
#define _STORE_CHESS_MENUAL_

#include "debug.h"
#include <fstream>
#include "chessboard.h"
#include <string>

class StoreChessManual
{
private:
   StoreChessManual();
public:
   ~StoreChessManual(); 
private:
   static StoreChessManual* s;
private:
   std::ifstream ifile;
   std::ofstream ofile;
   enum in_out{
     in,
     out
   };
private:
   int open_file(const std::string&,const enum in_out);
   void close_file(const enum in_out);
   int read_file(const std::string&,const enum in_out);
   int ops_file(const std::string&);
public:
   StoreChessManual* get_chess_manual();
};

#endif // storechessmanual.h
