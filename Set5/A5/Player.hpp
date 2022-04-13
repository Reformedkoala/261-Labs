/* CSCI 261: Assignment 5: A5 - Wild Left-Center-Right Simulation
 *
 * Author: Garrett Thompson
 * 
 * Wild Left Center Right PLayer Class implementation
 * 
 *
 */
#include <iostream>
using namespace std;

class Player {
  public:
    /**
     * @brief The default constructor of the player
     * 
     */
    Player();
    /**
     * @brief The overloaded constructor of the player to set the value of the player
     * 
     */
    Player(int playerVal);
    /**
     * @brief Getter for the player number
     * 
     */
    int getPlayer();
    /**
     * @brief Getter for the chip number
     * 
     */
    int getChips();
    /**
     * @brief overloaded equality operator
     * 
     * @param OTHER object to compare to the left side value
     * 
     */
    Player& operator=(const Player& OTHER);
    /**
     * @brief Player number data member
     * 
     */
    int mPlayerNum;
    /**
     * @brief Player chip data member
     * 
     */
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
