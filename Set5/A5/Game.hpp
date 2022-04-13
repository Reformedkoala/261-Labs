#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "DoublyLinkedList.hpp"
#include "Player.hpp"
using namespace std;

class Game {
  public:
    Game(int userIn);
    ~Game();
    int getCurrPlayer();
    bool getDirection();
    bool endCheck();
    void gameTurn();
    int rollDie();
    void playerWin();
  private:
    DoublyLinkedList<Player> currPlayers;
    int mCenterChips;
    int mGameSize;
    int mCurrPlayer;
    bool mDirection;
};

Game::Game(int userIn){
  mDirection = 1;
  mGameSize = userIn;
  mCurrPlayer = 1;
  mCenterChips = 0;
  for(int i = 1; i < userIn + 1; i++){
    currPlayers.insert(userIn, Player(i));
  }
}


Game::~Game(){
  currPlayers.~DoublyLinkedList();
}


int Game::getCurrPlayer(){
    return mCurrPlayer;
}

bool Game::getDirection(){
    return mDirection;
}


bool Game::endCheck(){
  int playerCheck = 0;
  for(int i = 0; i < mGameSize; i++){
    if (currPlayers.get(i).getChips() > 0){playerCheck += 1;}
  }
  if(playerCheck > 1){return 1;}
  else{return 0;}
}

int Game::rollDie(){
  int x = rand() % (7-0+1) +0;
  return x;
}


void Game::gameTurn(){
  Player Player1 = currPlayers.get(mCurrPlayer-1);
  Player Player2 = currPlayers.get(mGameSize-1);
  Player Player3 = currPlayers.get(mCurrPlayer-2);
  Player Player4 = currPlayers.get(mCurrPlayer);
  Player Player5 = currPlayers.get(0);
  int userDie = 0;
  int playerSkip = 0;
  if(Player1.getChips() > 3){
    userDie = 3;
  } else{
    userDie = Player1.getChips();
  }
  cout << "Player #" << mCurrPlayer << " has " << Player1.getChips() << " left" << endl;
  cout << "Rolling " << userDie << " dice" << endl;
  for(int i = 0; i < userDie; i++){
    int x = rollDie();
    if(x == 0){
        cout << "Rolled a " << x << " - keep!" << endl;
    } else if(x == 1){
        cout << "Rolled a " << x << " - keep!" << endl;
    } else if(x == 2){
        cout << "Rolled a " << x << " - keep!" << endl;
    } else if(x == 3){
      if(mCurrPlayer == 1){
        Player1.mChipNum -= 1;
        Player2.mChipNum += 1;
        currPlayers.set(mCurrPlayer-1, Player1);
        currPlayers.set(mGameSize-1, Player2);
        cout << "Rolled a " << x << " - give left - Player #"<< mCurrPlayer << " has " << currPlayers.get(mCurrPlayer-1).getChips() << " chips - Player #"<< mGameSize << " has "<< currPlayers.get(mGameSize-1).getChips() << " chips" << endl;
      }else{
        Player1.mChipNum -= 1;
        Player3.mChipNum += 1;
        currPlayers.set(mCurrPlayer-1, Player1);
        currPlayers.set(mCurrPlayer-2, Player3);
        cout << "Rolled a " << x << " - give left - Player #"<< mCurrPlayer << " has " << currPlayers.get(mCurrPlayer-1).getChips() << " chips - Player #"<< mCurrPlayer-1 << " has "<< currPlayers.get(mCurrPlayer-2).getChips() << " chips" << endl;
      }
    } else if(x == 4){
      if(mCurrPlayer == mGameSize){
        Player1.mChipNum -= 1;
        Player5.mChipNum += 1;
        currPlayers.set(mCurrPlayer-1, Player1);
        currPlayers.set(0, Player5);
        cout << "Rolled a " << x << " - give right - Player #"<< mCurrPlayer << " has " << currPlayers.get(mCurrPlayer-1).getChips() << " chips - Player #1" << " has "<< currPlayers.get(0).getChips() << " chips" << endl;
      }else{
        Player1.mChipNum -= 1;
        Player4.mChipNum += 1;
        currPlayers.set(mCurrPlayer-1, Player1);
        currPlayers.set(mCurrPlayer, Player4);
        cout << "Rolled a " << x << " - give right - Player #"<< mCurrPlayer << " has " << currPlayers.get(mCurrPlayer-1).getChips() << " chips - Player #"<< mCurrPlayer+1 << " has "<< currPlayers.get(mCurrPlayer).getChips() << " chips" << endl;
      }
    } else if(x == 5){
      Player1.mChipNum -= 1;
      mCenterChips += 1;
      currPlayers.set(mCurrPlayer-1, Player1);
      cout << "Rolled a " << x << " - give center - Player #"<< mCurrPlayer << " has " << currPlayers.get(mCurrPlayer-1).getChips() << " - Center has " << mCenterChips << " chips" << endl;
    } else if(x == 6){
      cout << "Rolled a " << x << " - reverse!" << endl;
      if(mDirection == 1){
          mDirection = 0;
      } else{
          mDirection = 1;
      }
    } else{
        playerSkip += 1;
        cout << "Rolled a " << x << " - skip! skipping " << playerSkip << " players" << endl;
    }
  }
  if(mDirection == 1){
    if(playerSkip == 0 && mCurrPlayer < mGameSize){
      mCurrPlayer += 1;
    } else if( playerSkip != 0 && mCurrPlayer + playerSkip <= mGameSize){
      mCurrPlayer += playerSkip;
    } else if ( playerSkip == 0 && mCurrPlayer == mGameSize){
      mCurrPlayer = 1;
    } else{
      mCurrPlayer += playerSkip;
      mCurrPlayer -= mGameSize;
      mCurrPlayer += 1;
    }
  } else{
    if(playerSkip == 0 && mCurrPlayer > 1 ){
      mCurrPlayer -= 1;
    } else if( playerSkip != 0 && mCurrPlayer - playerSkip >  0){
      mCurrPlayer -= playerSkip;
    } else if ( playerSkip == 0 && mCurrPlayer == 1){
      mCurrPlayer = mGameSize;
    } else{
      mCurrPlayer -= playerSkip;
      mCurrPlayer += mGameSize;
      mCurrPlayer -= 1;
    }
  }
}


void Game::playerWin(){
  for(int i = 0; i < mGameSize; i++){
    if ( currPlayers.get(i).getChips()>0){
      cout << "Player #" << currPlayers.get(i).mPlayerNum << " wins with " << currPlayers.get(i).mChipNum << " chips left after";
      break;
    }
  }
}