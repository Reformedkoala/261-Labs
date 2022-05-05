/* CSCI 261: Final Project: Casino
 *
 * Garrett Thompson
 * 
 * This is the implementation for the Player class of my project that helps define what a player is to the computer and provides me with tons of functionality and usage throughout the 
 * program. A bulk of the player class is initializing it as well as saving the data after the user is done. Making the user experience fluid was the key with this class and 
 * allowing them to create their own player in the casino was the goal.
 * 
 * 
 */
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include "Player.h"
using namespace std;

Player::Player(){
    // Default constructor that allows the user to choose a username and initializes a file with the name of their player
    string username;
    cout << "What would you like your username to be?" << endl;
    getline(cin, username);
    cout << "Your account has been initialized with 1000 dollars under the username of " << username << endl;
    mUsername = username;
    mBalance = 1000;
    mGamesPlayed = 0;
    mGamesWon = 0;
    mGamesLost = 0;
    mWinrate = 0;
    mGamesPlayedTypes.push_back(0);
    mGamesPlayedTypes.push_back(0);
    mGamesPlayedTypes.push_back(0);
    mPlayerFile = username +".txt";
}

Player::Player(string inputFileName){
    //Overloaded constructor that accounts for if the user enter a faulty file name by creating what they entered and informing them as such
    string tempString;
    int tempInt;
    ifstream fileIn;
    fileIn.open(inputFileName);
    if (fileIn.fail()) {
        cout << "File failed to open your acount will now be created with the username you entered." << endl;
        cout << "Your account has been initialized with 1000 dollars under the username of " << inputFileName << endl;
        mUsername = inputFileName;
        mBalance = 1000;
        mGamesPlayed = 0;
        mGamesWon = 0;
        mGamesLost = 0;
        mWinrate = 0;
        mGamesPlayedTypes.push_back(0);
        mGamesPlayedTypes.push_back(0);
        mGamesPlayedTypes.push_back(0);
        mPlayerFile = inputFileName +".txt";
        return;
    // This reads in the file the user has specified
    }else{
        mPlayerFile = inputFileName;
        cout << "User's file opened successfully" << endl;
        fileIn >> mUsername;
        fileIn >> mUsername;
        fileIn >> tempString;
        fileIn >> mBalance;
        fileIn >> tempString;
        fileIn >> mGamesPlayed;
        fileIn >> tempString;
        fileIn >> mGamesWon;
        fileIn >> tempString;
        fileIn >> mGamesLost;
        fileIn >> tempString;
        fileIn >> mWinrate;
        fileIn >> tempString;
        fileIn >> tempInt;
        mGamesPlayedTypes.push_back(tempInt);
        fileIn >> tempString;
        fileIn >> tempInt;
        mGamesPlayedTypes.push_back(tempInt);
        fileIn >> tempString;
        fileIn >> tempInt;
        mGamesPlayedTypes.push_back(tempInt);
        cout << "Account successfully loaded, please enjoy!" << endl;
        fileIn.close();
    }
} 


Player::~Player(){
    // Default destructor of the file that handles the case of the file not being able to open or a user deleting it while playing by just exiting the program
    ofstream outputFile;
    outputFile.open(mPlayerFile);
    if (outputFile.fail()) {
        cerr << "Error opening user's file please try again";
        exit(EXIT_FAILURE);
    }
    // Does all the writing of the output file and overwrites the old data
    outputFile << "Username: " << mUsername << "\n";
    outputFile << "Balance: " << mBalance << "\n";
    outputFile << "Played: " << mGamesPlayed << "\n";
    outputFile << "Won: " << mGamesWon << "\n";
    outputFile << "Lost: " << mGamesLost << "\n";
    outputFile << "Winrate: " << (float(mGamesWon)/float(mGamesPlayed)) * 100 << "\n";
    outputFile << "Roulette: " << mGamesPlayedTypes.at(0) << "\n";
    outputFile << "Blackjack: " << mGamesPlayedTypes.at(1) << "\n";
    outputFile << "Slots: " << mGamesPlayedTypes.at(2) << "\n";
    cout << "Player data saved successfully" << endl;
}


void Player::printStats(){
    // Print Stats method that just returns all of the current users stats
    cout << "Username: " << mUsername << endl;
    cout << "Balance: " << mBalance << endl;
    cout << "Played: " << mGamesPlayed << endl;
    cout << "Won: " << mGamesWon << endl;
    cout << "Lost: " << mGamesLost << endl;
    cout << "Winrate: " << (float(mGamesWon)/float(mGamesPlayed)) * 100 << "%" << endl;
    cout << "Roulette: " << mGamesPlayedTypes.at(0) << endl;
    cout << "Blackjack: " << mGamesPlayedTypes.at(1) << endl;
    cout << "Slots: " << mGamesPlayedTypes.at(2) << endl;
}

//EVERYTHING BELOW IS JUST GETTERS AND SETTERS THAT SIMPLY RETURN OR SET VALUES THEREFORE I WILL NOT COMMENT ALL OF THEM.
void Player::printBalance(){
    cout << "Balance: " << mBalance << endl; 
}


int Player::getBalance(){
    return mBalance;
}

void Player::setBalance(const int VALUE){
    mBalance = VALUE;
}

unsigned int Player::getGamesPlayed(){
    return mGamesPlayed;
}

void Player::setGamesPlayed(const int VALUE){
    mGamesPlayed = VALUE;
}

unsigned int Player::getGamesWon(){
    return mGamesWon;
}

void Player::setGamesWon(const int VALUE){
    mGamesWon = VALUE;
}

unsigned int Player::getGamesLost(){
    return mGamesLost;
}

void Player::setGamesLost(const int VALUE){
    mGamesLost = VALUE;
}

float Player::getWinrate(){
    return mWinrate;
}

void Player::setWinrate(const int VALUE){
    mWinrate = VALUE;
}

string Player::getmUsername(){
    return mUsername;
}

void Player::setRoulettePlayed(const int VALUE){
    mGamesPlayedTypes.at(0) = VALUE;
}

void Player::setBlackjackPlayed(const int VALUE){
    mGamesPlayedTypes.at(1) = VALUE;
}

void Player::setSlotsPlayed(const int VALUE){
    mGamesPlayedTypes.at(2) = VALUE;
}

int Player::getRoulettePlayed(){
    return mGamesPlayedTypes.at(0);
}

int Player::getBlackjackPlayed(){
    return mGamesPlayedTypes.at(1);
}

int Player::getSlotsPlayed(){
    return mGamesPlayedTypes.at(2);
}