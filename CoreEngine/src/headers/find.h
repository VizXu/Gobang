#ifndef FIND_H
#define FIND_H

class find_out
{
public:
 find_out(int x = 0, int y = 0):x_p(x),y_p(y){}
 bool operator()(board_position& pos){
    return pos.x_pos == x_p && pos.y_pos == y_p;
 }
private:
 int x_p;
 int y_p;
};

#endif //endif
