/* CSCI 261: Assignment 7: A7 - Triangle Land
 *
 * Garrett Thompson
 * 
 * This assignment is meant to practice polymorphism and inheritance of classes as well as virtual functions.  The assignment allows us to draw the c++ logo in SFML through 
 * triangles.
 * 
 */
#include <SFML/Graphics.hpp>
using namespace sf;
#include "EquilateralTriangle.h"
#include <cmath>
#include <iostream>
bool EquilateralTriangle::setCoordinates(double x1, double y1, double x2, double y2, double x3, double y3){
  // Implemented equilateral triangle to determine if the sides are the same and if the coordinates are valid
  int d1 = sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
  int d2 = sqrt((x3-x2)*(x3-x2) + (y3-y2)*(y3-y2));
  int d3 = sqrt((x1-x3)*(x1-x3) + (y1-y3)*(y1-y3));

  if(d1 > 0 && d2 > 0 && d3 > 0 && ( d1+d2 >= d3 || d2+d3 >= d1 || d1+d3 >= d2 ) && ((d1==d2) && (d2 == d3) && (d3 == d1))){
    verticeList.push_back(x1);
    verticeList.push_back(y1);
    verticeList.push_back(x2);
    verticeList.push_back(y2);
    verticeList.push_back(x3);
    verticeList.push_back(y3);
    return true;
  }
  else{
    return false;
  }
}