/* CSCI 261 Lab 2C: Pass-by-Value & Pass-by-Reference 
 *
 * Author: Garrett Thompson
 *
 * This program was made to convert polar and cartesian coordinates between each other.  This is done through PBV and PBR functions that allow us to reuse variables and change
 * them in the function.
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

// Funciton prototypes to declare our functions to later define them in the program
void polar_to_cartesian(const double radius, const double angle, double& xCoord, double& yCoord);
void cartesian_to_polar(const double xCoord, const double yCoord, double& radius, double& angle);

int main() {
    int userChoice = 0;
    double radius;
    double angle;
    double xCoord;
    double yCoord;
    cout << "Would you like to convert from polar to cartesian (r, Theta) -> (x, y) or cartesian to polar (x, y) -> (r, Theta)" << endl;
    cout << "1) Polar to Cartesian" << endl;
    cout << "2) Cartesian to Polar" << endl;
    cout << "Enter Here: ";
    cin >> userChoice;
    // Determines which branch of the program to send us down based on user input
    if (userChoice == 1) {
      cout << "Please enter the polar coordinates for radius then the angle in degrees." << endl;
      cout << "Enter radius: ";
      cin >> radius;
      cout << "Enter angle in degrees: ";
      cin >> angle;
      polar_to_cartesian(radius, angle, xCoord, yCoord);
      cout << "The cartesian values for the polar coordinates you entered are: " << xCoord << " , " << yCoord << endl;
    }
    else {
      cout << "Please enter the polar coordinates for radius then the angle in degrees." << endl;
      cout << "Enter X coordinate: ";
      cin >> xCoord;
      cout << "Enter Y coordinate: ";
      cin >> yCoord;
      cartesian_to_polar(xCoord, yCoord, radius, angle);
      cout << "The polar values for the cartesian coordinates you entered are: " << radius << " , " << angle << endl;

    }
}

/**
 * @brief Converts from Polar to Cartesian
 * 
 * @param radius determines the radius of the coordinate in the polar plane
 * @param angle determines the angle of the coordinate in the polar plane
 * @param xCoord passed by reference to the function so we can modify it within and return it
 * @param yCoord passed by reference to the function so we can modify it within and return it
 * 
 */
void polar_to_cartesian(const double radius, const double angle, double& xCoord, double& yCoord) {
  xCoord = radius * cos((angle*3.14159)/180);
  yCoord = radius * sin((angle*3.14159)/180);
}

/**
 * @brief Converts from Cartesian to Polar
 * 
 * @param radius passed by reference to the function so we can modify it within and return it
 * @param angle passed by reference to the function so we can modify it within and return it
 * @param xCoord determines the xCoord in the cartesian plane
 * @param yCoord determines the yCoord in the cartesian plane
 * 
 */
void cartesian_to_polar(const double xCoord, const double yCoord, double& radius, double& angle) {
  radius = sqrt((xCoord*xCoord) + (yCoord*yCoord));
  angle = (atan((yCoord/xCoord)) * 180)/3.14159;
}
