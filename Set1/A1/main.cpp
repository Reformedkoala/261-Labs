/* CSCI 261: Assignment 1: A1 - Rock Paper Scissor Throw Down!
 *
 * Author: Garrett Thompson
 *
 * This program allows the user to play a game of Rock, Paper, Scissors with the computer by having them pick a value and then the computer
 * picking a random value between 0, 1, and 2.  Then determining if that is Rock, Paper, or Scissors respectively.  The game also keeps track of 
 * the amount of times a user wins, loses, and ties and prints it out once the user quits.
 */
// The include section adds extra definitions from the C++ standard library.
#include <iostream> // For cin, cout, etc.

// We will (most of the time) use the standard library namespace in our programs.
using namespace std;
#include <cmath> // for math
#include <cstdlib> // for random
#include <ctime> // for time
#include <cctype> // for upper so I don't have to write double the if statements

// Define any constants below this comment.

// Must have a function named "main", which is the starting point of a C++ program.
int main() {
  // Initializing variables that should be outside of loop
  char continue_val = 'Y';
  int win_count = 0;
  int loss_count = 0;
  int tie_count = 0;
  // Loop to continue games based on user choice
  while(continue_val == 'Y') {
    // Seeding random and using it once so it's not too close to the next time the program runs.
    srand(time(0));
    rand();
    // Initializing user choice and a welcome message
    char choice;
    cout << "Welcome one and all to a round of Rock, Paper, Scissors! (Enter P, R or S)" << endl;
    cout << "Player: ";
    cin >> choice;
    // Standardizing user input to R, P, or S
    choice = toupper(choice);
    int comp_choice = rand() % 3;
    // Creating and determining outcome of player vs. computer
    if (choice == 'R') {
        cout << "Player chose Rock" << endl;
    }
    else if (choice == 'P') {
        cout << "Player chose Paper" << endl;
    }
    else {
        cout << "Player chose Scissors" << endl;
    }
    if (comp_choice == 0) {
        cout << "Computer chose Rock" << endl;
    }
    else if (comp_choice == 1) {
        cout << "Computer chose Paper" << endl;
    }
    else {
        cout << "Computer chose Scissors" << endl;
    }
    if (choice == 'R' && comp_choice == 0) {
        cout << "Rock ties Rock" << endl;
        cout << "Tie!" << endl;
        tie_count++;
    }
    else if (choice == 'P' && comp_choice == 1) {
        cout << "Paper ties Paper" << endl;
        cout << "Tie!" << endl;
        tie_count++;
    }
    else if (choice == 'S' && comp_choice == 2) {
        cout << "Scissors ties Scissors" << endl;
        cout << "Tie!" << endl;
        tie_count++;
    }
    else if (choice == 'R' && comp_choice == 2){
        cout << "Rock beats Scissors" << endl;
        cout << "Player wins!" << endl;
        win_count++;
    }
    else if (choice == 'P' && comp_choice == 0){
        cout << "Paper beats Rock" << endl;
        cout << "Player wins!" << endl;
        win_count++;
    }
    else if (choice == 'S' && comp_choice == 1){
        cout << "Scissors beats Paper" << endl;
        cout << "Player wins!" << endl;
        win_count++;
    }
    else if (choice == 'R' && comp_choice == 1){
        cout << "Paper beats Rock" << endl;
        cout << "Computer wins!" << endl;
        loss_count++;
    }
    else if (choice == 'P' && comp_choice == 2){
        cout << "Scissors beats Paper" << endl;
        cout << "Computer wins!" << endl;
        loss_count++;
    }
    else if (choice == 'S' && comp_choice == 0){
        cout << "Rock beats Scissors" << endl;
        cout << "Computer wins!" << endl;
        loss_count++;
    }
    cout << "Do you want to play again? (Y/N) ";
    cin >> continue_val;
    }
  // Ending game and printing out game stats
  cout << "Thanks for playing!" << endl;
  cout << "You won " << win_count << " game(s), lost " << loss_count << " game(s), and tied " << tie_count << " game(s). " << endl;
  return 0; // signals the operating system that our program ended OK.
}