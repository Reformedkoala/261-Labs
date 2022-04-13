#include <iostream>
using namespace std;

class Player {
  public:
    Player();
    Player(int playerVal);
    int getPlayer();
    int getChips();
    Player& operator=(const Player& OTHER);
    int mPlayerNum;
    int mChipNum;
};

Player::Player(){
    mPlayerNum = 0;
    mChipNum = 0;
}


Player::Player(int playerVal){
    mPlayerNum = playerVal;
    mChipNum = 3;
}

int Player::getPlayer(){
    return mPlayerNum;
}

int Player::getChips(){
    return mChipNum;
}


Player& Player::operator=(const Player& OTHER){
  this->mChipNum = OTHER.mChipNum;
  this->mPlayerNum = OTHER.mPlayerNum;
  return *this;
}
