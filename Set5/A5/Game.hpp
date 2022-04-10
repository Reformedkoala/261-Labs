#include <iostream>
#include "DoublyLinkedList.hpp"
#include "Player.hpp"
using namespace std;

class Game {
  public:
    Game(int userIn);
    int getCurrPlayer();
    bool getDirection();
  private:
    DoublyLinkedList<Player> currPlayers;
    int mGameSize;
    int mCurrPlayer;
    bool mDirection;
};

Game::Game(int userIn){
  mGameSize = userIn;
  mCurrPlayer = 1;
  for(int i = 1; i < userIn + 1; i++){
    currPlayers.insert(userIn+1, Player(i));
  }

}

int Game::getCurrPlayer(){
    return mCurrPlayer;
}

bool Game::getDirection(){
    return mDirection;
}