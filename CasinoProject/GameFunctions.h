#ifndef GAMEFUNCTIONS_H
#define GAMEFUNCTIONS_H
#include <string>
#include "Player.h"
using namespace std;

void rouletteChoice(Player &Player1);

string rouletteGame();

void blackjackGame(Player &Player1);

void playerDraw(int &playerTotal, vector<string>& playerCards, int suit, int card, vector<vector<string>> deckList);

void dealerDraw(int &dealerTotal, vector<string>& dealerCards, int suit, int card, vector<vector<string>> deckList);

#endif