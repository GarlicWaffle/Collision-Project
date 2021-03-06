#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <vector>
#include <iostream>
#include "map.hpp"
using namespace std;

class player
{
  public:
    int getPosX();
    int getPosY();
    bool update();
    player(map* m);
    void reset(map* m);
  private:
    int posX;
    int posY;
    int jumpCounter;
    map* m;
};

#endif
