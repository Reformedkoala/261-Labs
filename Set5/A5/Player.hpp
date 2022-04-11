#include <iostream>
using namespace std;

class Player {
  public:
    Player();
    Player(int playerVal);
    int getPlayer();
    int getChips();
    void giveChip(Player targetPlayer);
    void giveCenter();

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

void Player::giveChip(Player targetPlayer){
  targetPlayer.mChipNum +=1;
  this->mChipNum -=1;
}

void Player::giveCenter(){
  mChipNum -=1;
}