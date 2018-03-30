#ifndef GAMEINFO_H
#define GAMEINFO_H

class gameinfo
{
private:
    int xpos;
    int ypos;
    int size;
    int level;
    int status;
    int steps;
public:
    gameinfo();
    ~gameinfo();
public:
    int getXpos() const;
    void setXpos(int);
    int getYpos() const;
    void setYpos(int);
    int getSize() const;
    void setSize(int);
    int getLevel() const;
    void setLevel(int);
    int getStatus() const;
    void setStatus(int);
    int getStep() const;
};

class ChessboardInfo
{
public:
    gameinfo info;
    char* chessboard;
public:
    int getStep() const;
    int getSize() const;
    char* getChessboard() const;
    bool copyInfoFromClient(char* src, int dataSize);
};

#endif // GAMEINFO_H
