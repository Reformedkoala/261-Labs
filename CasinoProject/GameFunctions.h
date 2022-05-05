/* CSCI 261: Final Project: Casino
 *
 * Garrett Thompson
 * 
 * This is the header file for the bulk of the program. The implementation from this header is what took most of the time and is what most of the game runs in.
 * 
 * 
 */
#ifndef GAMEFUNCTIONS_H
#define GAMEFUNCTIONS_H
#include <string>
#include "Player.h"
using namespace std;

/**
* @brief rouletteChoice that simply runs the bets and choices of the user
* 
* @param Player1 Player object passed to roulette by reference in order to modify the player stats
* 
*/
void rouletteChoice(Player &Player1);

/**
* @brief rouletteGame that performs the actual game of roulette and returns where the player actually landed so I didn't have to copy and paste
* 
*/
string rouletteGame();

/**
* @brief blackjackGame that performs the actual game of blackjack for the user
*
* @param Player1 Player object passed to blackjack by reference in order to modify the player stats
* 
*/
void blackjackGame(Player &Player1);

/**
* @brief playerDraw draws for the player and inserts a card into their deck as well as updating the total and checking for any errors
*
* @param playerTotal The current total of the cards the player holds
* @param playerCards The current list of cards the player holds while playing
* @param suit the random number generated to determine the suit of the card
* @param card the random number generated to determine the number of the card
* @param deckList the deckList of all the possible cards to pull
* 
*/
void playerDraw(int &playerTotal, vector<string>& playerCards, int suit, int card, vector<vector<string>> deckList);

/**
* @brief dealerDraw draws for the dealer and inserts a card into their deck as well as updating the total and checking for any errors
*
* @param dealerTotal The current total of the cards the dealer holds
* @param dealerCards The current list of cards the dealer holds while playing
* @param suit the random number generated to determine the suit of the card
* @param card the random number generated to determine the number of the card
* @param deckList the deckList of all the possible cards to pull
* 
*/
void dealerDraw(int &dealerTotal, vector<string>& dealerCards, int suit, int card, vector<vector<string>> deckList);

/**
* @brief singLinesSlots that performs the actual game of slots for the user
*
* @param Player1 Player object passed to slots by reference in order to modify the player stats
* 
*/
void singleLineSlots(Player &Player1);

#endif