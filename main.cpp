#include "map.hpp"
#include "player.hpp"
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "Windows.h"
using namespace std;

void menu()
{
  cout << "=====[Welcome to Cube Game]=====" << endl;
  cout << "Guide Your Cube Through All Three Mazes To Win" << endl;
  cout << "See The Time It Takes To Detect Collsion Below The Map" << endl;
  cout << "=====[Controls]=====" << endl;
  cout << "WASD Or Arrow Keys To Move" << endl;
  cout << "Press Space Bar To Jump" << endl;
  cout << "Press E To Change Maps" << endl;
  cout << "=====[Select Collision Type]=====" << endl;
  cout << "1) Two Dimensional Vector Collision" << endl;
  cout << "2) QuadTree Collision" << endl;
  cout << "3) HashTable Collision" << endl;
}

int main(int argc, char const *argv[])
{
  menu();
  string type = "";
  while (type != "1" && type != "2" && type != "3")
    cin >> type;
  cout << "Start" << endl;
  map m(stoi(type)-1,1);
  cout << "end" << endl;
  cin.ignore();
  player p(&m);
  m.print(p.getPosX(),p.getPosY());
  cin.ignore();
  bool checker = false;
  while (checker == false)
  {
    Sleep(50);
    if (p.update() == true)
    {
      m.print(p.getPosX(),p.getPosY());
    }
    if (GetKeyState(0x45) < 0)
    {
      checker = true;
    }
  }
  map mB(stoi(type)-1,2);
  p.reset(&mB);
  mB.print(p.getPosX(),p.getPosY());
  checker = false;
  Sleep(1000);
  while (checker == false)
  {
    Sleep(50);
    if (p.update() == true)
    {
      mB.print(p.getPosX(),p.getPosY());
    }
    if (GetKeyState(0x45) < 0)
    {
      checker = true;
    }
  }
  map mC(stoi(type)-1,3);
  p.reset(&mC);
  mC.print(p.getPosX(),p.getPosY());
  checker = false;
  Sleep(1000);
  while (checker == false)
  {
    Sleep(50);
    if (p.update() == true)
    {
      mC.print(p.getPosX(),p.getPosY());
    }
    if (GetKeyState(0x45) < 0)
    {
      checker = true;
    }
  }
  cout << "Goodbye" << endl;
  return 0;
}
