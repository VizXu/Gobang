#ifndef _STORE_CHESS_MENUAL_
#define _STORE_CHESS_MENUAL_

#include "debug.h"
#include <fstream>
#include "chessboard.h"
#include "chessboardinfo.h"
#include <string>

class chessboard_info;

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
   int write_file(const std::string&, const enum in_out);
public:
   int store_chessboard_info_to_file(const std::string&,chessboard_info&);
   int read_chessboard_info_from_file(const std::string&,chessboard_info&);
public:
   static StoreChessManual* get_chess_manual();
};

#endif // storechessmanual.h
