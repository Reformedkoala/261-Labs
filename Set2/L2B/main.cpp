/* CSCI 261 Lab 2B: Procedural Programming with Functions
 *
 * Author: Garrett Thompson
 *
 * 
 */

// The include section adds extra definitions from the C++ standard library.
#include <iostream> // For cin, cout, etc.
#include <cmath> // for math
#include <cstdlib> // for random
#include <ctime> // for time
#include <iomanip> // for formatting
// We will (most of the time) use the standard library namespace in our programs.
using namespace std;

void generate_random_integer(int minVal, int maxVal, bool minIn, bool maxIn);
void generate_random_float(float minVal, float maxVal, bool minIn, bool maxIn);

// Must have a function named "main", which is the starting point of a C++ program.
int main() {
  srand(time(0));
  rand();
  float minVal;
  float maxVal;
  bool minIn;
  bool maxIn;
  cout << "Enter the minimum value: ";
  cin >> minVal;
  cout << "Enter the maximum value: ";
  cin >> maxVal;
  cout << "Enter whether or not the minimum should be inclusive ";
  cin >> minIn;
  cout << "Enter whether or not the maximum should be inclusive ";
  cin >> maxIn;
  generate_random_integer(minVal, maxVal, minIn, maxIn);
  generate_random_float(minVal, maxVal, minIn, maxIn);
  return 0; // signals the operating system that our program ended OK.
}

void generate_random_integer(int minVal, int maxVal, bool minIn, bool maxIn) {
  int i = 0;
  if (minIn == true && maxIn == true) {
      for (i = 0; i < 10; i++) {
      int randInt = rand() % (int)(maxVal - minVal + 1) + minVal;
      cout << randInt << endl;
    }
  } else if (minIn == true && maxIn == false) {
      for (i = 0; i < 10; i++) {
        int randInt = rand() % (int)(maxVal - minVal + 1) + minVal;
        if (randInt == maxVal){
          randInt -= 1;
        }
        cout << randInt << endl;
    }
  } else if (minIn == false && maxIn == true) {
    for (i = 0; i < 10; i++) {
      int randInt = rand() % (int)(maxVal - minVal + 1) + minVal;
      if (randInt == minVal){
        randInt += 1;
      }
      cout << randInt << endl;
    }
  } else{
    for (i = 0; i < 10; i++) {
      int randInt = rand() % (int)(maxVal - minVal + 1) + minVal;
      if (randInt == minVal) {
        randInt += 1;
      }else if(randInt == maxVal){
        randInt -=1;
      }
      cout << randInt << endl;
    }
  }
}
void generate_random_float(float minVal, float maxVal, bool minIn, bool maxIn) {
  int i = 0;
  if (minIn == true && maxIn == true) {
    for (i =0; i < 10; i++) {
      float randFloat = rand() / (float)RAND_MAX * (maxVal - minVal) + minVal;
      cout << setprecision(4) << randFloat << endl;
    }
  } else if (minIn == true && maxIn == false) {
    for (i =0; i < 10; i++) {
      float randFloat = rand() / (float)RAND_MAX * (maxVal - minVal) + minVal;
      if(randFloat == maxVal){
        randFloat -= .001;   
      }
      cout << setprecision(4) << randFloat << endl;
    }
  } else if (minIn == false && maxIn == true) {
    for (i =0; i < 10; i++) {
      float randFloat = rand() / (float)RAND_MAX * (maxVal - minVal) + minVal;
      if(randFloat == maxVal){
        randFloat += .001;   
      }
      cout << setprecision(4) << randFloat << endl;
    }
  } else{
    for (i =0; i < 10; i++) {
      float randFloat = rand() / (float)RAND_MAX * (maxVal - minVal) + minVal;
      if(randFloat == maxVal){
        randFloat -= .001;   
      }
      else if(randFloat == minVal){
        randFloat += .001;
      }
      cout << setprecision(4) << randFloat << endl;
    }
  }
}