/* CSCI 261: Final Project: Casino
 *
 * Garrett Thompson
 * 
 * This final project is meant to simulate three popular casino games. The three games are blackjack, slot machines, and roulette. The player has specific user data unique to them
 * through file input and output and can create a new user when first booting up the game. The user then has the choice to play one of the three games, print out their stats, or
 * print out their balance. After the user chooses a game they want to play they will make a bet according to the game type and how they want to play. What makes this casino special
 * is the fact that the player has the ability to go into the negative as it is just a game, so the player can enter whatever bet amount they want and experiment. The casino 
 * is meant to be more of a simulation then anything, but the player can choose to play legitimately and back out when they go into the negative and just restart.
 * 
 * 
 */
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#include "Player.h"
#include "GameFunctions.h"

int main(int argc, char* argv[]) {
    // Initialization of the variables for our file. The user can enter a file when they first load the program or choose to create a new player when they load the game.
    string filename;
    int playerChoice;
    if(argc == 1) {
        while(true){
            // The user can choose whether they would like to load a profile or choose a new player
            cout << "Would you like to create a new player or use an existing profile?" << endl;
            cout << "1) Create new player" << endl;
            cout << "2) Use existing profile" << endl;
            cout << "Enter here: ";
            cin >> playerChoice;
            // Checking for user input to ensure a branch is not gone down mistakenly
            if (!cin.fail() && playerChoice >= 1 && playerChoice <= 2){
                // Prompting the user for input on their player name or the file they want to load
                if( playerChoice == 1){
                    cout << "Please enter the name of your player here: ";
                    cin >> filename;
                    cout << "Loading player" << endl;
                    break;
                }else if (playerChoice == 2) {
                    cout << "Please enter the name for your file here: ";
                    cin >> filename;
                    cout << "Loading player" << endl;
                    break;
                    }
                }else{
                    cerr << "Invalid input please enter a number between 1 and 2" << endl;
                    cin.clear();
                    char badChar; 
                    do { badChar = cin.get(); } while( badChar != '\n' );
                    }
            }
    } else if(argc == 2) {
        filename = argv[1];
        cout << "Loading player" << endl;
    } else {
        cerr << "Usage: " << argv[0] << " [filename]" << endl;
        cerr << "  filename   - optional file to open upon start" << endl;
        return -2;
    }
    // Creating the play object from the file that was just loaded or created
    Player Player1(filename);
    int userChoice;
    while(true) {
        // Main logic branch for what the user would like to do
        cout << "What game would you like to play?" << endl;
        cout << "1) Roulette" << endl;
        cout << "2) Blackjack" << endl;
        cout << "3) Slot Machine" << endl;
        cout << "4) Print Stats" << endl;
        cout << "5) Print Balance" << endl;
        cout << "6) Quit" << endl;
        cout << "Enter choice here: ";
        cin >> userChoice;
        // Ensures the user enters proper input for the game and calls the function according to the choice. Everything is abstracted away according to object oriented programming.
        if (!cin.fail() && userChoice >= 1 && userChoice <= 6) {
            if(userChoice == 1){
                rouletteChoice(Player1);
            } else if (userChoice == 2) {
                blackjackGame(Player1);
            } else if (userChoice == 3){
                singleLineSlots(Player1);
            } else if(userChoice == 4){
                Player1.printStats();
            } else if(userChoice == 5){
                Player1.printBalance();
            } else{
                break;
            }
        } else{
            cerr << "Invalid input please enter a number between 1 and 6" << endl;
            cin.clear();
            char badChar; 
            do { badChar = cin.get(); } while( badChar != '\n' );
            }
    }
    
    return 0;
}