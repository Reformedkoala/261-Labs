/* CSCI 261: Final Project: Casino
 *
 * Garrett Thompson
 * 
 * This is the implementation file for the bulk of the program. The implementation might be a bit messy in some spots especially with roulette as I implemented a bunch of 
 * different ways for the user to bet and choose what they want to bet on. That involved some pretty long if statements as I didn't know of any other way to do it. One other note
 * is that the adjustment when the player wins or loses definitely could've been abstracted somewhat to a function or even done in the player class, but I didn't realize that
 * until I had already implemented it in Blackjack and did not want to update and refactor everything. Besides the slight abstraction improvement that I could make in that case
 * I believe the program is pretty solid and was made to fit what I wanted and needed.
 * 
 * 
 */
#include "GameFunctions.h"
#include <vector>
#include <stdlib.h>
#include <time.h>

void rouletteChoice( Player &Player1){
    // Main while loop for the program of roulette that essentially allows the user to make varying bets based on what they want to do
    while(true){
        // Intializing user choices and some other variables used throughout to determine results
        int userChoice;
        int userChoice2;
        string result;
        // Main user choice for what they would like to bet on which consists of betting on the high or low side of the table
        cout << "Would you like to make an inside or outside bet" << endl;
        cout << "1) Inside (more risky and profitable singular/group bets)" << endl;
        cout << "2) Outside (less risky and profitable collection bets)" << endl;
        cout << "3) Go back" << endl;
        cout << "Enter here: ";
        cin >> userChoice; 
        if (!cin.fail() && userChoice >= 1 && userChoice <= 3) {
            if(userChoice == 1){
                while(true){
                    // User choice if they chose the high side of the table which is much more specialized bets with higher risk
                    cout << "What bet would you like to make" << endl;
                    cout << "1) Single (Bet on a single number) Payout of 35:1" << endl;
                    cout << "2) Basket (Bet on 0-00-1-2-3) Payout of 6:1" << endl;
                    cout << "3) Go back" << endl;
                    cout << "Enter here: ";
                    cin >> userChoice2;
                    if (!cin.fail() && userChoice >= 1 && userChoice <= 3) {
                        if(userChoice2 == 1){
                            // User choice for if they chose single and now need to enter a number 
                            string userNumber;
                            unsigned int userBet;
                            cout << "What number would you like to bet on? (0-36 and 00) ";
                            cin >> userNumber;
                            cout << "How much would you like to bet? (any amount of your balance) ";
                            cin >> userBet;
                            result = rouletteGame();
                            cout << "Ball landed on " << result << endl;
                            // If statements to check if the user won or not
                            if(result == userNumber){
                                cout << "Congratulations you won!" << endl;
                                Player1.setBalance(userBet*36 + Player1.getBalance());
                                Player1.setGamesPlayed(Player1.getGamesPlayed()+1);
                                Player1.setGamesWon(Player1.getGamesWon()+1);
                                Player1.setRoulettePlayed(Player1.getRoulettePlayed()+1);
                            } else{
                                cout << "Try again!" << endl;
                                Player1.setBalance(Player1.getBalance() - userBet);
                                Player1.setGamesPlayed(Player1.getGamesPlayed()+1);
                                Player1.setGamesLost(Player1.getGamesLost()+1);
                                Player1.setRoulettePlayed(Player1.getRoulettePlayed()+1);
                            }
                        } else if(userChoice2 == 2){
                            // User choice for if they chose the basket which has specific places on the roulette table
                            unsigned int userBet;
                            cout << "How much would you like to bet? (any amount of your balance) ";
                            cin >> userBet;
                            result = rouletteGame();
                            cout << "Ball landed on " << result << endl;
                            // if statements to check the win condition
                            if(result == "0" || result == "00" || result == "1" || result == "2" || result == "3"){
                                cout << "Congratulations you won!" << endl;
                                Player1.setBalance(userBet*7 + Player1.getBalance());
                                Player1.setGamesPlayed(Player1.getGamesPlayed()+1);
                                Player1.setGamesWon(Player1.getGamesWon()+1);
                                Player1.setRoulettePlayed(Player1.getRoulettePlayed()+1);
                            } else{
                                cout << "Try again!" << endl;
                                Player1.setBalance(Player1.getBalance() - userBet);
                                Player1.setGamesPlayed(Player1.getGamesPlayed()+1);
                                Player1.setGamesLost(Player1.getGamesLost()+1);
                                Player1.setRoulettePlayed(Player1.getRoulettePlayed()+1);
                            }
                        } else{
                            break;
                        }
                    } else{
                        cerr << "Invalid input please enter a number between 1 and 2" << endl;
                        cin.clear();
                        char badChar; 
                        do { badChar = cin.get(); } while( badChar != '\n' );
                    }
                }
            } else if (userChoice == 2) {
                while(true){
                    // Main bets for if the user chose the low side of the table which involves betting on big groups of numbers in the wheel
                    cout << "What bet would you like to make" << endl;
                    cout << "1) Low (1-18) Payout of 1:1" << endl;
                    cout << "2) High (19-36) Payout of 1:1" << endl;
                    cout << "3) Red (All red numbers) Payout of 1:1"<< endl;
                    cout << "4) Black (All black numbers) Payout of 1:1" << endl;
                    cout << "5) Even (All even numbers) Payout of 1:1" << endl;
                    cout << "6) Odd (All odd numbers) Payout of 1:1" << endl;
                    cout << "7) Go back" << endl;
                    cout << "Enter here: ";
                    cin >> userChoice2;
                    if (!cin.fail() && userChoice >= 1 && userChoice <= 7) {
                        if(userChoice2 == 1){
                            unsigned int userBet;
                            // asks for the users bet
                            cout << "How much would you like to bet? (any amount of your balance) ";
                            cin >> userBet;
                            result = rouletteGame();
                            cout << "Ball landed on " << result << endl;
                            // long chain of if statements to match to the condition the user chooses this repeats for all of the low side bets
                            if(result == "1" || result == "2" || result == "3" || result == "4" || result == "5" || result == "6" || result == "7" || result == "8" || result == "9" || result == "10" || result == "11" || result == "12" || result == "13" || result == "14" || result == "15" || result == "16" || result == "17" || result == "18"){
                                cout << "Congratulations you won!" << endl;
                                Player1.setBalance(userBet*2 + Player1.getBalance());
                                Player1.setGamesPlayed(Player1.getGamesPlayed()+1);
                                Player1.setGamesWon(Player1.getGamesWon()+1);
                                Player1.setRoulettePlayed(Player1.getRoulettePlayed()+1);
                            } else{
                                cout << "Try again!" << endl;
                                Player1.setBalance(Player1.getBalance() - userBet);
                                Player1.setGamesPlayed(Player1.getGamesPlayed()+1);
                                Player1.setGamesLost(Player1.getGamesLost()+1);
                                Player1.setRoulettePlayed(Player1.getRoulettePlayed()+1);
                            }
                        } else if(userChoice2 == 2){
                            unsigned int userBet;
                            cout << "How much would you like to bet? (any amount of your balance) ";
                            cin >> userBet;
                            result = rouletteGame();
                            cout << "Ball landed on " << result << endl;
                            // long chain of if statements to match to the condition the user chooses this repeats for all of the low side bets
                            if(result == "19" || result == "20" || result == "21" || result == "22" || result == "23" || result == "24" || result == "25" || result == "26" || result == "27" || result == "28" || result == "29" || result == "30" || result == "31" || result == "32" || result == "33" || result == "34" || result == "35" || result == "36"){
                                cout << "Congratulations you won!" << endl;
                                Player1.setBalance(userBet*2 + Player1.getBalance());
                                Player1.setGamesPlayed(Player1.getGamesPlayed()+1);
                                Player1.setGamesWon(Player1.getGamesWon()+1);
                                Player1.setRoulettePlayed(Player1.getRoulettePlayed()+1);
                            } else{
                                cout << "Try again!" << endl;
                                Player1.setBalance(Player1.getBalance() - userBet);
                                Player1.setGamesPlayed(Player1.getGamesPlayed()+1);
                                Player1.setGamesLost(Player1.getGamesLost()+1);
                                Player1.setRoulettePlayed(Player1.getRoulettePlayed()+1);
                            }
                        } else if(userChoice2 == 3){
                            unsigned int userBet;
                            cout << "How much would you like to bet? (any amount of your balance) ";
                            cin >> userBet;
                            result = rouletteGame();
                            // long chain of if statements to match to the condition the user chooses this repeats for all of the low side bets
                            if(result == "32" || result == "19" || result == "21" || result == "25" || result == "34" || result == "27" || result == "36" || result == "30" || result == "23" || result == "5" || result == "16" || result == "1" || result == "14" || result == "9" || result == "18" || result == "7" || result == "12" || result == "3"){
                                cout << "Congratulations you won!" << endl;
                                Player1.setBalance(userBet*2 + Player1.getBalance());
                                Player1.setGamesPlayed(Player1.getGamesPlayed()+1);
                                Player1.setGamesWon(Player1.getGamesWon()+1);
                                Player1.setRoulettePlayed(Player1.getRoulettePlayed()+1);
                            } else{
                                cout << "Try again!" << endl;
                                Player1.setBalance(Player1.getBalance() - userBet);
                                Player1.setGamesPlayed(Player1.getGamesPlayed()+1);
                                Player1.setGamesLost(Player1.getGamesLost()+1);
                                Player1.setRoulettePlayed(Player1.getRoulettePlayed()+1);
                            }
                        } else if(userChoice2 == 4){
                            unsigned int userBet;
                            cout << "How much would you like to bet? (any amount of your balance) ";
                            cin >> userBet;
                            result = rouletteGame();
                            // long chain of if statements to match to the condition the user chooses this repeats for all of the low side bets
                            if(result == "15" || result == "4" || result == "2" || result == "17" || result == "6" || result == "13" || result == "11" || result == "8" || result == "10" || result == "24" || result == "33" || result == "20" || result == "32" || result == "22" || result == "29" || result == "28" || result == "35" || result == "26"){
                                cout << "Congratulations you won!" << endl;
                                Player1.setBalance(userBet*2 + Player1.getBalance());
                                Player1.setGamesPlayed(Player1.getGamesPlayed()+1);
                                Player1.setGamesWon(Player1.getGamesWon()+1);
                                Player1.setRoulettePlayed(Player1.getRoulettePlayed()+1);
                            } else{
                                cout << "Try again!" << endl;
                                Player1.setBalance(Player1.getBalance() - userBet);
                                Player1.setGamesPlayed(Player1.getGamesPlayed()+1);
                                Player1.setGamesLost(Player1.getGamesLost()+1);
                                Player1.setRoulettePlayed(Player1.getRoulettePlayed()+1);
                            }
                        } else if(userChoice2 == 5){
                            unsigned int userBet;
                            cout << "How much would you like to bet? (any amount of your balance) ";
                            cin >> userBet;
                            result = rouletteGame();
                            // long chain of if statements to match to the condition the user chooses this repeats for all of the low side bets
                            if(result == "2" || result == "4" || result == "6" || result == "8" || result == "10" || result == "12" || result == "14" || result == "16" || result == "18" || result == "20" || result == "22" || result == "24" || result == "26" || result == "28" || result == "30" || result == "32" || result == "34" || result == "36"){
                                cout << "Congratulations you won!" << endl;
                                Player1.setBalance(userBet*2 + Player1.getBalance());
                                Player1.setGamesPlayed(Player1.getGamesPlayed()+1);
                                Player1.setGamesWon(Player1.getGamesWon()+1);
                                Player1.setRoulettePlayed(Player1.getRoulettePlayed()+1);
                            } else{
                                cout << "Try again!" << endl;
                                Player1.setBalance(Player1.getBalance() - userBet);
                                Player1.setGamesPlayed(Player1.getGamesPlayed()+1);
                                Player1.setGamesLost(Player1.getGamesLost()+1);
                                Player1.setRoulettePlayed(Player1.getRoulettePlayed()+1);
                            }
                        } else if(userChoice2 == 6){
                            unsigned int userBet;
                            cout << "How much would you like to bet? (any amount of your balance) ";
                            cin >> userBet;
                            result = rouletteGame();
                            // long chain of if statements to match to the condition the user chooses this repeats for all of the low side bets
                            if(result == "1" || result == "3" || result == "5" || result == "7" || result == "9" || result == "11" || result == "13" || result == "15" || result == "17" || result == "19" || result == "21" || result == "23" || result == "25" || result == "27" || result == "29" || result == "31" || result == "33" || result == "35"){
                                cout << "Congratulations you won!" << endl;
                                Player1.setBalance(userBet*2 + Player1.getBalance());
                                Player1.setGamesPlayed(Player1.getGamesPlayed()+1);
                                Player1.setGamesWon(Player1.getGamesWon()+1);
                                Player1.setRoulettePlayed(Player1.getRoulettePlayed()+1);
                            } else{
                                cout << "Try again!" << endl;
                                Player1.setBalance(Player1.getBalance() - userBet);
                                Player1.setGamesPlayed(Player1.getGamesPlayed()+1);
                                Player1.setGamesLost(Player1.getGamesLost()+1);
                                Player1.setRoulettePlayed(Player1.getRoulettePlayed()+1);
                            }
                        } else{
                            break;
                        }
                    } else{
                        cerr << "Invalid input please enter a number between 1 and 2" << endl;
                        cin.clear();
                        char badChar; 
                        do { badChar = cin.get(); } while( badChar != '\n' );
                    }
                }
            } else{
                break;
        }
        }else{
            cerr << "Invalid input please enter a number between 1 and 2" << endl;
            cin.clear();
            char badChar; 
            do { badChar = cin.get(); } while( badChar != '\n' );
        }
        
    }
}


string rouletteGame(){
    vector<string> rouletteWheel = {"0","28","9","26","30","11","7","20","32","17","5","22","34","15","3","24","36","13","1","00","27","10","25","29","12","8","19","31","18"
                                    ,"6","21","33","16","4","23","35","14","2"};
    srand(time(0));
    rand();
    int x = rand() % (37-0+1) + 0;
    return rouletteWheel.at(x);
}

void blackjackGame(Player &Player1){
    //  Game of blackjack assuming 8 decks so it is possible to draw the same card and not run out of that same card
    // Initializes all of the variables used through the program and the main deck that we choose from
    vector<vector<string>> deckList;
    vector<string> heartsList = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace"};
    vector<string> diamondsList = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace"};
    vector<string> spadesList = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace"};
    vector<string> clubsList = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace"};
    deckList.push_back(heartsList);
    deckList.push_back(diamondsList);
    deckList.push_back(spadesList);
    deckList.push_back(clubsList);
    int dealerTotal;
    int playerTotal;
    int playerBet;
    int playerChoice;
    int suit;
    int card;
    vector<string> dealerCards;
    vector<string> playerCards;
    string tempString;
    // Warning to the user for the special case of the ACE which is specific in blackjack where it can be 11 or 1 the computer chooses for the user
    cout << "WARNING: if you roll an Ace the game will determine what is best for you without you choosing. Once it has chosen you can not change it." << endl;
    cout << "How much would you like to bet: ";
    cin >> playerBet;
    // seeding the random function with the current time
    srand(time(0));
    rand();
    // Setting up the two cards for the player and the dealer
    for(int i = 0; i < 2; i++){
        suit = rand() % (3-0+1) + 0;
        card = rand() % (13-0+1) + 0;
        playerDraw(playerTotal, playerCards, suit, card, deckList);
    }
    for(int i = 0; i < 2; i++){
        suit = rand() % (3-0+1) + 0;
        card = rand() % (13-0+1) + 0;
        dealerDraw(dealerTotal, dealerCards, suit, card, deckList);
    }
    while(true){
        // main loop for the blackjack program that allows the user to hit, double down, or stand based on their cards
        cout << "Your cards are ";
        for(unsigned int i = 0; i < playerCards.size(); i++){
            cout << "'" << playerCards.at(i) << "', ";
        }
        cout << " and your total is " << playerTotal << endl;
        cout << "The dealer has a " << dealerCards.at(0) << " and one other card" << endl;
        cout << "Will you..." << endl;
        cout << "1) Hit" << endl;
        cout << "2) Double down" << endl;
        cout << "3) Stand (ends the game)" << endl;
        cout << "Enter choice here: ";
        cin >> playerChoice;
        if (!cin.fail() && playerChoice >= 1 && playerChoice <= 3){
            // Hits the user with a card and checks if they busted or not
            if(playerChoice == 1){
                suit = rand() % (3-0+1) + 0;
                card = rand() % (13-0+1) + 0;
                playerDraw(playerTotal, playerCards, suit, card, deckList);
                if(playerTotal > 21){
                    cout << "You busted at " << playerTotal << endl; 
                    cout << "Your cards were ";
                    for(unsigned int i = 0; i < playerCards.size(); i++){
                        cout << "'" << playerCards.at(i) << "', ";
                    }
                    cout << " and your total is " << playerTotal << endl;
                    break;
                }
            // Allows the user to double their bet if they feel confident and draw a card
            } else if(playerChoice == 2){
                playerBet *= 2;
                cout << "You now have a bet of " << playerBet << endl;
                suit = rand() % (3-0+1) + 0;
                card = rand() % (13-0+1) + 0;
                playerDraw(playerTotal, playerCards, suit, card, deckList);
                if(playerTotal > 21){
                    cout << "You busted at " << playerTotal << endl; 
                    break;
                }else{
                    break;
                }
                // if the user chooses to stand the loop ends and a winner is determined
            } else{
                cout << "You chose to stand with a total of " << playerTotal << endl;
                break;
            }
        }else{
            cerr << "Invalid input please enter a number between 1 and 3" << endl;
            cin.clear();
            char badChar; 
            do { badChar = cin.get(); } while( badChar != '\n' );
        }
    }
    // Does the checking if the player loses or wins: first checks if the player is over 21 as that is an automatic loss
    if (playerTotal > 21){
        cout << "You lost better luck next time!" << endl;
        Player1.setBalance(Player1.getBalance() - playerBet);
        Player1.setGamesPlayed(Player1.getGamesPlayed()+1);
        Player1.setGamesLost(Player1.getGamesLost()+1);
        Player1.setBlackjackPlayed(Player1.getBlackjackPlayed()+1);
    // Otherwise allows the dealer to draw until over 17 or if they hit 21
    } else{
        while(dealerTotal < 17){
            dealerDraw(dealerTotal, dealerCards, suit, card, deckList);
        }
        // If the dealer busts the player wins
        if (dealerTotal > 21){
            cout << "Dealer busted" << endl;
            cout << "His cards were ";
            for(unsigned int i = 0; i < dealerCards.size(); i++){
                cout << "'" << dealerCards.at(i) << "', ";
            }
            cout << " and his total was " << dealerTotal << endl;
            Player1.setBalance(playerBet*2 + Player1.getBalance());
            Player1.setGamesPlayed(Player1.getGamesPlayed()+1);
            Player1.setGamesWon(Player1.getGamesWon()+1);
            Player1.setBlackjackPlayed(Player1.getBlackjackPlayed()+1);
        // If the dealer is greater then the player or equal to them and didn't bust the player loses
        } else if (dealerTotal >= playerTotal){
            cout << "You had less then the dealer, better luck next time!" << endl;
            cout << "His cards were ";
            for(unsigned int i = 0; i < dealerCards.size(); i++){
                cout << "'" << dealerCards.at(i) << "', ";
            }
            cout << " and his total was " << dealerTotal << endl;
            Player1.setBalance(Player1.getBalance() - playerBet);
            Player1.setGamesPlayed(Player1.getGamesPlayed()+1);
            Player1.setGamesLost(Player1.getGamesLost()+1);
            Player1.setBlackjackPlayed(Player1.getBlackjackPlayed()+1);
        // The player wins if they had more then the dealer and didn't bust
        } else{
            cout << "You had more then the dealer and didn't bust, congratulations!" << endl;
            cout << "His cards were ";
            for(unsigned int i = 0; i < dealerCards.size(); i++){
                cout << "'" << dealerCards.at(i) << "', ";
            }
            cout << " and his total was " << dealerTotal << endl;
            Player1.setBalance(playerBet*2 + Player1.getBalance());
            Player1.setGamesPlayed(Player1.getGamesPlayed()+1);
            Player1.setGamesWon(Player1.getGamesWon()+1);
            Player1.setBlackjackPlayed(Player1.getBlackjackPlayed()+1);
        }
    }
}



void playerDraw(int &playerTotal, vector<string>& playerCards, int suit, int card, vector<vector<string>> deckList){
    // Player draw function for abstraction purposes as to not repeat the determing of the card the user has
    string tempString;
    // If statements determining what suit the user gets and what card number they receive and then stores it as string to print out as well as changes the value
    if(suit == 0){
        tempString = deckList.at(suit).at(card) + " of hearts";
        if(deckList.at(suit).at(card) == "Jack" || deckList.at(suit).at(card) == "Queen" || deckList.at(suit).at(card) == "King"){
            playerTotal += 10;
        } else if (deckList.at(suit).at(card) == "Ace" && playerTotal + 11 <= 21 ){
            playerTotal += 11;
        } else if (deckList.at(suit).at(card) == "Ace" && playerTotal + 11 > 21 ){
            playerTotal += 1;
        } else{
            playerTotal += stoi(deckList.at(suit).at(card));
        }
        playerCards.push_back(tempString);
    }else if (suit == 1){
        tempString = deckList.at(suit).at(card) + " of diamonds";
        if(deckList.at(suit).at(card) == "Jack" || deckList.at(suit).at(card) == "Queen" || deckList.at(suit).at(card) == "King"){
            playerTotal += 10;
        } else if (deckList.at(suit).at(card) == "Ace" && playerTotal + 11 <= 21 ){
            playerTotal += 11;
        } else if (deckList.at(suit).at(card) == "Ace" && playerTotal + 11 > 21 ){
            playerTotal += 1;
        } else{
            playerTotal += stoi(deckList.at(suit).at(card));
        }
        playerCards.push_back(tempString);
    }else if (suit == 2){
        tempString = deckList.at(suit).at(card) + " of spades";
        if(deckList.at(suit).at(card) == "Jack" || deckList.at(suit).at(card) == "Queen" || deckList.at(suit).at(card) == "King"){
            playerTotal += 10;
        } else if (deckList.at(suit).at(card) == "Ace" && playerTotal + 11 <= 21 ){
            playerTotal += 11;
        } else if (deckList.at(suit).at(card) == "Ace" && playerTotal + 11 > 21 ){
            playerTotal += 1;
        } else{
            playerTotal += stoi(deckList.at(suit).at(card));
        }
        playerCards.push_back(tempString);
    }else if (suit == 3){
        tempString = deckList.at(suit).at(card) + " of clubs";
        if(deckList.at(suit).at(card) == "Jack" || deckList.at(suit).at(card) == "Queen" || deckList.at(suit).at(card) == "King"){
            playerTotal += 10;
        } else if (deckList.at(suit).at(card) == "Ace" && playerTotal + 11 <= 21 ){
            playerTotal += 11;
        } else if (deckList.at(suit).at(card) == "Ace" && playerTotal + 11 > 21 ){
            playerTotal += 1;
        } else{
            playerTotal += stoi(deckList.at(suit).at(card));
        }
        playerCards.push_back(tempString);
    }
}

void dealerDraw(int &dealerTotal, vector<string>& dealerCards, int suit, int card, vector<vector<string>> deckList){
    // Dealer draw function for abstraction purposes as to not repeat the determing of the card the dealer has
    string tempString;
    // If statements determining what suit the dealer gets and what card number they receive and then stores it as string to print out as well as changes the value
    if(suit == 0){
        tempString = deckList.at(suit).at(card) + " of hearts";
        if(deckList.at(suit).at(card) == "Jack" || deckList.at(suit).at(card) == "Queen" || deckList.at(suit).at(card) == "King"){
            dealerTotal += 10;
        } else if (deckList.at(suit).at(card) == "Ace" && dealerTotal + 11 <= 21 ){
            dealerTotal += 11;
        } else if (deckList.at(suit).at(card) == "Ace" && dealerTotal + 11 > 21 ){
            dealerTotal += 1;
        } else{
            dealerTotal += stoi(deckList.at(suit).at(card));
        }
        dealerCards.push_back(tempString);
    }else if (suit == 1){
        tempString = deckList.at(suit).at(card) + " of diamonds";
        if(deckList.at(suit).at(card) == "Jack" || deckList.at(suit).at(card) == "Queen" || deckList.at(suit).at(card) == "King"){
            dealerTotal += 10;
        } else if (deckList.at(suit).at(card) == "Ace" && dealerTotal + 11 <= 21 ){
            dealerTotal += 11;
        } else if (deckList.at(suit).at(card) == "Ace" && dealerTotal + 11 > 21 ){
            dealerTotal += 1;
        } else{
            dealerTotal += stoi(deckList.at(suit).at(card));
        }
        dealerCards.push_back(tempString);
    }else if (suit == 2){
        tempString = deckList.at(suit).at(card) + " of spades";
        if(deckList.at(suit).at(card) == "Jack" || deckList.at(suit).at(card) == "Queen" || deckList.at(suit).at(card) == "King"){
            dealerTotal += 10;
        } else if (deckList.at(suit).at(card) == "Ace" && dealerTotal + 11 <= 21 ){
            dealerTotal += 11;
        } else if (deckList.at(suit).at(card) == "Ace" && dealerTotal + 11 > 21 ){
            dealerTotal += 1;
        } else{
            dealerTotal += stoi(deckList.at(suit).at(card));
        }
        dealerCards.push_back(tempString);
    }else if (suit == 3){
        tempString = deckList.at(suit).at(card) + " of clubs";
        if(deckList.at(suit).at(card) == "Jack" || deckList.at(suit).at(card) == "Queen" || deckList.at(suit).at(card) == "King"){
            dealerTotal += 10;
        } else if (deckList.at(suit).at(card) == "Ace" && dealerTotal + 11 <= 21 ){
            dealerTotal += 11;
        } else if (deckList.at(suit).at(card) == "Ace" && dealerTotal + 11 > 21 ){
            dealerTotal += 1;
        } else{
            dealerTotal += stoi(deckList.at(suit).at(card));
        }
        dealerCards.push_back(tempString);
    }
}


void singleLineSlots(Player &Player1){
    // Initialization of everything used in the slots function
    // Seeds random
    srand(time(0));
    rand();
    int userBet;
    int userChoice;
    int firstSlot;
    int secondSlot;
    int thirdSlot;
    // Creates the single line slot
    vector<string> singleLine = {"7", "BARBAR", "BAR", "Diamond", "Cherry", "Lemon"};
    // Prints out the user's choices and what they can earn if they roll what is listed
    cout << "Hello welcome to the Single Line Slot Machine of No Consequences Casino." << endl;
    cout << "The rules here are simple, this is a high stakes Single Line Slot machine with 6 different Icon options." << endl;
    cout << "3 7's gives 1000x payout" << endl;
    cout << "3 BARBAR's gives 100x payout" << endl;
    cout << "3 BAR's gives 50x payout" << endl;
    cout << "3 Diamonds's gives 25x payout" << endl;
    cout << "3 Cherry's gives 10x payout" << endl;
    cout << "Finally, 3 Lemon's gives 5x payout" << endl;
    // Fair warning that there are no partial wins or mixing of icons
    cout << "WARNING: THERE ARE NO PARTIAL-WINS OR MIXING OF ICONS FOR PAYOUTS" << endl;
    cout << "How much would you like to bet (A bet matching the player's balance will result in double the payout): ";
    cin >> userBet;
    while(true){
        // Performs the rolling the first second and third slot of the line
        firstSlot = rand() % (5-0+1) + 0;
        secondSlot = rand() % (5-0+1) + 0;
        thirdSlot = rand() % (5-0+1) + 0;
        cout << "You rolled:" << endl;
        // Tells the user what they rolled
        cout << "| " << singleLine.at(firstSlot) << " | " << singleLine.at(secondSlot) << " | " << singleLine.at(thirdSlot) << " |"<< endl;
        // Long line of if statements only if all three are the same 
        if(singleLine.at(firstSlot) == singleLine.at(secondSlot) && singleLine.at(secondSlot) == singleLine.at(thirdSlot) && singleLine.at(thirdSlot) == singleLine.at(firstSlot)){
            if (singleLine.at(firstSlot) == "7"){
                cout << "Congratulations you won with a payout of 1000x your bet!" << endl;
                // Changes the balance and games played of the player, this is repeated in every if statement
                Player1.setBalance(userBet*1000 + Player1.getBalance());
                Player1.setGamesPlayed(Player1.getGamesPlayed()+1);
                Player1.setGamesWon(Player1.getGamesWon()+1);
                Player1.setSlotsPlayed(Player1.getSlotsPlayed()+1);
            } else if (singleLine.at(firstSlot) == "BARBAR"){
                cout << "Congratulations you won with a payout of 100x your bet!" << endl;
                Player1.setBalance(userBet*100 + Player1.getBalance());
                Player1.setGamesPlayed(Player1.getGamesPlayed()+1);
                Player1.setGamesWon(Player1.getGamesWon()+1);
                Player1.setSlotsPlayed(Player1.getSlotsPlayed()+1);
            } else if (singleLine.at(firstSlot) == "BAR"){
                cout << "Congratulations you won with a payout of 50x your bet!" << endl;
                Player1.setBalance(userBet*50 + Player1.getBalance());
                Player1.setGamesPlayed(Player1.getGamesPlayed()+1);
                Player1.setGamesWon(Player1.getGamesWon()+1);
                Player1.setSlotsPlayed(Player1.getSlotsPlayed()+1);
            } else if (singleLine.at(firstSlot) == "Diamond"){
                cout << "Congratulations you won with a payout of 25x your bet!" << endl;
                Player1.setBalance(userBet*25 + Player1.getBalance());
                Player1.setGamesPlayed(Player1.getGamesPlayed()+1);
                Player1.setGamesWon(Player1.getGamesWon()+1);
                Player1.setSlotsPlayed(Player1.getSlotsPlayed()+1);
            } else if (singleLine.at(firstSlot) == "Cherry"){
                cout << "Congratulations you won with a payout of 10x your bet!" << endl;
                Player1.setBalance(userBet*10 + Player1.getBalance());
                Player1.setGamesPlayed(Player1.getGamesPlayed()+1);
                Player1.setGamesWon(Player1.getGamesWon()+1);
                Player1.setSlotsPlayed(Player1.getSlotsPlayed()+1);
            } else if (singleLine.at(firstSlot) == "Lemon"){
                cout << "Congratulations you won with a payout of 5x your bet!" << endl;
                Player1.setBalance(userBet*5 + Player1.getBalance());
                Player1.setGamesPlayed(Player1.getGamesPlayed()+1);
                Player1.setGamesWon(Player1.getGamesWon()+1);
                Player1.setSlotsPlayed(Player1.getSlotsPlayed()+1);
            }
        // Else the player loses
        }else{
            cout << "You Lost, better luck next time!" << endl;
            Player1.setBalance(Player1.getBalance() - userBet);
            Player1.setGamesPlayed(Player1.getGamesPlayed()+1);
            Player1.setGamesLost(Player1.getGamesLost()+1);
            Player1.setSlotsPlayed(Player1.getSlotsPlayed()+1); 
        }
        // Asks the user if they would like to play again or play again with the same bet and does so
        cout << "1) Play again" << endl;
        cout << "2) Play again with same bet" << endl;
        cout << "3) Quit" << endl;
        cout << "Enter here: ";
        cin >> userChoice;
        if (!cin.fail() && userChoice >= 1 && userChoice <= 3){
            if(userChoice == 1){
                cout << "How much would you like to bet (A bet matching the player's balance will result in double the payout): ";
                cin >> userBet;
            } else if(userChoice == 2){
                continue;
            } else{
                break;
            }
        }else{
            cerr << "Invalid input please enter a number between 1 and 3" << endl;
            cin.clear();
            char badChar; 
            do { badChar = cin.get(); } while( badChar != '\n' );
        }

    }

    
}