/* CSCI 261: Assignment 7: A7 - Triangle Land
 *
 * Garrett Thompson
 * 
 * This assignment is meant to practice polymorphism and inheritance of classes as well as virtual functions.  The assignment allows us to draw the c++ logo in SFML through 
 * triangles.
 * 
 */
#ifndef ISOSCELESTRIANGLE_H
#define ISOSCELESTRIANGLE_H
#include <SFML/Graphics.hpp>
#include <vector>
#include "Triangle.h"
using namespace sf;
using namespace std;

class IsoscelesTriangle: public Triangle{
  public:
    /**
    * @brief implemented setCoordinates for each triangle to determine it's position and if it is valid or not
    * 
    * @param x1
    * @param y1
    * @param x2
    * @param y2
    * @param x3
    * @param y3
    * 
    */
    bool setCoordinates(double x1, double y1, double x2, double y2, double x3, double y3);
};
#endif