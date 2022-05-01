#include "GameFunctions.h"
#include <vector>
#include <stdlib.h>
#include <time.h>

void rouletteChoice( Player &Player1){
    while(true){
        int userChoice;
        int userChoice2;
        string result;
        cout << "Would you like to make an inside or outside bet" << endl;
        cout << "1) Inside (more risky and profitable singular/group bets)" << endl;
        cout << "2) Outside (less risky and profitable collection bets)" << endl;
        cout << "3) Go back" << endl;
        cout << "Enter here: ";
        cin >> userChoice; 
        if (!cin.fail() && userChoice >= 1 && userChoice <= 3) {
            if(userChoice == 1){
                while(true){
                    cout << "What bet would you like to make" << endl;
                    cout << "1) Single (Bet on a single number) Payout of 35:1" << endl;
                    cout << "2) Basket (Bet on 0-00-1-2-3) Payout of 6:1" << endl;
                    cout << "3) Go back" << endl;
                    cout << "Enter here: ";
                    cin >> userChoice2;
                    if (!cin.fail() && userChoice >= 1 && userChoice <= 3) {
                        if(userChoice2 == 1){
                            string userNumber;
                            unsigned int userBet;
                            cout << "What number would you like to bet on? (0-36 and 00) ";
                            cin >> userNumber;
                            cout << "How much would you like to bet? (any amount of your balance) ";
                            cin >> userBet;
                            result = rouletteGame();
                            cout << "Ball landed on " << result << endl;
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
                            unsigned int userBet;
                            cout << "How much would you like to bet? (any amount of your balance) ";
                            cin >> userBet;
                            result = rouletteGame();
                            cout << "Ball landed on " << result << endl;
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
                            cout << "How much would you like to bet? (any amount of your balance) ";
                            cin >> userBet;
                            result = rouletteGame();
                            cout << "Ball landed on " << result << endl;
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
