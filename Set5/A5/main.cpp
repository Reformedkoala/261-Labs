#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Game.hpp"
using namespace std;
/* CSCI 261: Assignment 5: A5 - Wild Left-Center-Right Simulation
 *
 * Author: Garrett Thompson
 * 
 * Main file for WIld Left Center Right implementation that just calls any objects I need to and controls the upper structure of the game and output for the most part
 * 
 *
 */

int main() {
  // Initializing user variables
  int userIn;
  int turnCount = 0;
  // Taking user input for how many players to make
  cout << "How many players are playing: ";
  cin >> userIn;
  // Calling the constructor for our game class
  Game mainGame(userIn);
  // seeding random for the die
  srand(time(0));
  rand();
  // Main loop for each turn and how I keep track of the turns
  while(mainGame.endCheck()){
    mainGame.gameTurn();
    turnCount += 1;
  }
  // Printing out the winning player
  mainGame.playerWin();
  // Printing out the turns
  cout << " " << turnCount << " turns" << endl;
  // Deconstructing and cleaning up
  mainGame.~Game();
  return 0;

}
