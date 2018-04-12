#ifndef CHESSBOARD_H_
#define CHESSBOARD_H_

#include <string>
#include "types.h"
#define BOARD_SIZE 15

#include "storechessmanual.h"
#include "chessboardinfo.h"

class chessboard_info;

class Chessboard
{
private:
    s8 board[BOARD_SIZE][BOARD_SIZE];
public:
    Chessboard(){
      for(int i = 0; i < BOARD_SIZE; i++){
        for(int j = 0;j < BOARD_SIZE; j++){
          board[i][j] = '+';
        }
      }
    }
    ~Chessboard(){}
    Chessboard& operator=(const Chessboard&) = delete;
    Chessboard& operator()(const Chessboard&) = delete;
public:
    int store_chessboard_info(const std::string&,chessboard_info&);
private:
    void get_chessboard(chessboard_info&);
private:
    u32 scan_board() const;
    bool is_board_empty() const;
private:
    bool is_site_empty(u32,u32) const;
public:
    bool set_chess(u32,u32,s8);
    s8   get_chess(u32,u32) const;
public:
    bool has_empty_site() const;
    void init(int);
};
#endif//chessboard.h
