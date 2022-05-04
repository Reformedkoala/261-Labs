#include <vector>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#include "Player.h"
#include "GameFunctions.h"

int main(int argc, char* argv[]) {
    
    string filename;
    int playerChoice;
    if(argc == 1) {
        while(true){
        cout << "Would you like to create a new player or use an existing profile?" << endl;
        cout << "1) Create new player" << endl;
        cout << "2) Use existing profile" << endl;
        cout << "Enter here: ";
        cin >> playerChoice;
        if (!cin.fail() && playerChoice >= 1 && playerChoice <= 2){
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

    Player Player1(filename);
    int userChoice;
    while(true) {
        cout << "What game would you like to play?" << endl;
        cout << "1) Roulette" << endl;
        cout << "2) Blackjack" << endl;
        cout << "3) Slot Machine" << endl;
        cout << "4) Print Stats" << endl;
        cout << "5) Print Balance" << endl;
        cout << "6) Quit" << endl;
        cout << "Enter choice here: ";
        cin >> userChoice;
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