#ifndef PLAYER_H
#define PLAYER_H
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Player{
    public:
        Player();
        Player(string inputFileName);
        ~Player();
        void printStats();
        void printBalance();
        int getBalance();
        void setBalance(const int VALUE);
        unsigned int getGamesPlayed();
        void setGamesPlayed(const int VALUE);
        unsigned int getGamesWon();
        void setGamesWon(const int VALUE);
        unsigned int getGamesLost();
        void setGamesLost(const int VALUE);
        float getWinrate();
        void setWinrate(const int VALUE);
        string getmUsername();
        void setRoulettePlayed(const int VALUE);
        int getRoulettePlayed();
        void setBlackjackPlayed(const int VALUE);
        int getBlackjackPlayed();
        void setSlotsPlayed(const int VALUE);
        int getSlotsPlayed();
        
    private:
        int mBalance;
        unsigned int mGamesPlayed;
        unsigned int mGamesWon;
        unsigned int mGamesLost;
        float mWinrate;
        string mUsername;
        string mPlayerFile;
        vector<int> mGamesPlayedTypes;
};

#endif