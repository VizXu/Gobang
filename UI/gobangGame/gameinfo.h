#ifndef GAMEINFO_H
#define GAMEINFO_H

class gameinfo
{
private:
    int xpos;
    int ypos;
    int size;
    int lelve;
    int status;
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
};

#endif // GAMEINFO_H
