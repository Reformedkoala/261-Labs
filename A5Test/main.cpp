#include <fstream>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "Game.hpp"
using namespace std;
/* CSCI 261: A4: Wavefront OBJ File Format
 *
 * Author: Garrett Thompson
 *
 * Reading in a wavefront OBJ File Format and verifying certain properties of the file as well as printing out based on user specification.
 * 
 */

int main() {
  int userIn;
  int turnCount = 0;
  cout << "How many players are playing: ";
  cin >> userIn;
  Game mainGame(userIn);
  srand(time(0));
  rand();
  while(mainGame.endCheck()){
    mainGame.gameTurn();
    turnCount += 1;
  }
  mainGame.playerWin();
  cout << " " << turnCount << " turns" << endl;
  mainGame.~Game();
  return 0;

}
