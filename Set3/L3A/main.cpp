/* CSCI 261 L3A: Array Min/Max
 *
 * Author: Garrett Thompson
 *
 * Iterate through the array we take in through user input in order to find the min and max of the values the user inputted.
 * 
 */

// The include section adds extra definitions from the C++ standard library.
#include <iostream> // For cin, cout, etc.
#include <cmath> // for math
#include <cstdlib> // for random
#include <ctime> // for time
#include <iomanip> // for formatting
#include <fstream> // for files
// We will (most of the time) use the standard library namespace in our programs.
using namespace std;


int main() {
  // Initialize all variables
  int i;
  int userIn;
  int userArray[15];
  int size = 15;
  int maximum;
  int minimum;
  cout << "Enter up to 15 non-zero numbers.  Enter zero to signal the end of data or enter all 15 items:" << endl;\
  // The loop to take in our user's values
  for (i = 0; i < 15; i++){
    cout << "Number " << i+1 << ": ";
    cin >> userIn;
    if (userIn == 0) {
        size = i;
        break;
    }
    else{
        userArray[i] = userIn;
    }
  }
  cout << "The numbers are: ";
  maximum = userArray[0];
  minimum = userArray[0];
  // The loop to iterate through the array and keep track of the min and max
  for (i = 0; i < size; i++){
    if(maximum < userArray[i]){
      maximum = userArray[i];
    }
    if(minimum > userArray[i]){
      minimum = userArray[i];
    }   
    cout << userArray[i] << " ";
  }
  cout << endl;
  cout << "The maximum value is: " << maximum << endl;
  cout << "The minimum value is: " << minimum << endl;
  cout << "Have a nice day!" << endl;
}
