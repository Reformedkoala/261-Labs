#include <iostream>
using namespace std;

class Player {
  public:
    Player();
    Player(int playerVal);
    int getPlayer();
    int getChips();
    void giveCenter();
    void subtractOne();
    void addOne();
    Player& operator=(const Player& OTHER);
  private:
    int mPlayerNum;
    int mChipNum;
};

Player::Player(){
    mPlayerNum = 0;
    mChipNum = 3;
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


void Player::giveCenter(){
  mChipNum -=1;
}

void Player::subtractOne(){
  mChipNum -=1;
}

void Player::addOne(){
  mChipNum +=1;
}


Player& Player::operator=(const Player& OTHER){
  this->mChipNum = OTHER.mChipNum;
  this->mPlayerNum = OTHER.mPlayerNum;
  return *this;
}
