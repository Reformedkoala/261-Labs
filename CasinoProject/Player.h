/* CSCI 261: Final Project: Casino
 *
 * Garrett Thompson
 * 
 * This is the header for the Player class of my project that helps define what a player is to the computer and provides me with tons of functionality and usage throughout the 
 * program. There could have been some more things in here that I could've cleverly implemented, but sometimes copying and pasting is easier then cleverness.
 * 
 * 
 */
#ifndef PLAYER_H
#define PLAYER_H
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Player{
    public:
        /**
        * @brief default constructor for the Player class
        * 
        */
        Player();
        /**
        * @brief Overloaded constructor for the Player class when a file is provided
        * 
        * @param inputFileName name of the file the user would like to open passed in as a string
        * 
        */
        Player(string inputFileName);
        /**
        * @brief Default destructor for the player class that save all of the user data to a file at the end of the program
        * 
        */
        ~Player();
        /**
        * @brief printStats method that prints out all of the users stats according to what is currently stored in the class
        * 
        */
        void printStats();
        /**
        * @brief printBalance method that prints out the users balance if they are only interested in that
        * 
        */
        void printBalance();
        /**
        * @brief getBalance method to create a getter for the balance
        * 
        */
        int getBalance();
        /**
        * @brief setBalance method to create a setter for the balance
        * 
        * @param VALUE value to set the balance to
        * 
        */
        void setBalance(const int VALUE);
        /**
        * @brief getGamesPlayed method to create a getter for the games the player has played
        * 
        */
        unsigned int getGamesPlayed();
        /**
        * @brief setGamesPlayed method to create a setter for the games played
        * 
        * @param VALUE value to set the games played to
        * 
        */
        void setGamesPlayed(const int VALUE);
        /**
        * @brief getGamesWon method to create a getter for the games the player has won
        * 
        */
        unsigned int getGamesWon();
        /**
        * @brief setGamesWon method to create a setter for the games won
        * 
        * @param VALUE value to set the games won to
        * 
        */
        void setGamesWon(const int VALUE);
        /**
        * @brief getGamesLost method to create a getter for the games the player has lost
        * 
        */
        unsigned int getGamesLost();
        /**
        * @brief setGamesLost method to create a setter for the games lost
        * 
        * @param VALUE value to set the games lost to
        * 
        */
        void setGamesLost(const int VALUE);
        /**
        * @brief getWinrate method to create a getter for the total winrate of the player
        * 
        */
        float getWinrate();
        /**
        * @brief setWinrate method to create a setter for the winrate of the player
        * 
        * @param VALUE value to set the winrate to
        * 
        */
        void setWinrate(const int VALUE);
        /**
        * @brief getmUsername method to create a getter for the username of the player
        * 
        */
        string getmUsername();
        /**
        * @brief setRoulettePlayed method to create a setter for the amount of times the player has played roulette
        * 
        * @param VALUE value to set the roulette played
        * 
        */
        void setRoulettePlayed(const int VALUE);
        /**
        * @brief getRoulettePlayed method to create a getter for amount of roulette the user has played
        * 
        */
        int getRoulettePlayed();
        /**
        * @brief setBalckjackPlayed method to create a setter for the amount of times the player has played blackjack
        * 
        * @param VALUE value to set the blackjack played
        * 
        */
        void setBlackjackPlayed(const int VALUE);
        /**
        * @brief getBlackjackPlayed method to create a getter for amount of blackjack the user has played
        * 
        */
        int getBlackjackPlayed();
        /**
        * @brief setslotsPlayed method to create a setter for the amount of times the player has played slots
        * 
        * @param VALUE value to set the slots played
        * 
        */
        void setSlotsPlayed(const int VALUE);
        /**
        * @brief getSlotsPlayed method to create a getter for amount of slots the user has played
        * 
        */
        int getSlotsPlayed();
        
    private:
        /**
        * @brief private balance data member
        * 
        */
        int mBalance;
        /**
        * @brief private games played data member
        * 
        */
        unsigned int mGamesPlayed;
        /**
        * @brief private games won data member
        * 
        */
        unsigned int mGamesWon;
        /**
        * @brief private games lost data member
        * 
        */
        unsigned int mGamesLost;
        /**
        * @brief private winrate data member
        * 
        */
        float mWinrate;
        /**
        * @brief private username data member
        * 
        */
        string mUsername;
        /**
        * @brief private player file data member
        * 
        */
        string mPlayerFile;
        /**
        * @brief private games played vector for all the different types of games they've played
        * 
        */
        vector<int> mGamesPlayedTypes;
};

#endif