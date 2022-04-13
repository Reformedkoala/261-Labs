#include <fstream>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "LinkedList.hpp"
#include "Rectangle.hpp"
using namespace std;
/* CSCI 261: Lab 5E - Procedural and Object-Oriented
 *
 * Author: Garrett Thompson
 *
 * Main file for Lab 5E in which we add rectangles to our linked list and sort them based on specified overloaded comparators in order to make our sort function object oriented
 * 
 */

int main() {
  int userIn;
  cout << "How many rectangles would you like to make?" << endl;
  cin >> userIn;
  srand(time(0));
  rand();

  LinkedList<Rectangle> rectangleList;
  for(int i = 0; i < userIn; i++){
    float randBase = rand() % (100-0+1) +0;
    float randHeight = rand() % (100-0+1) +0;
    Rectangle randRectangle = Rectangle(randBase, randHeight);
    rectangleList.pushBack(randRectangle);
  }
  for(int i = 0; i < userIn; i++){
    cout << rectangleList.at(i).getBase() << " X " << rectangleList.at(i).getHeight() << ", ";
  }
  cout << endl;
  rectangleList.merge_sort(rectangleList, 1);
  for(int i = 0; i < userIn; i++){
    cout << rectangleList.at(i).getBase() << " X " << rectangleList.at(i).getHeight() << ", ";
  }
  cout << endl;
  rectangleList.merge_sort(rectangleList, 2);
  for(int i = 0; i < userIn; i++){
    cout << rectangleList.at(i).getBase() << " X " << rectangleList.at(i).getHeight() << ", ";
  }
  cout << endl;
  return 0;
}