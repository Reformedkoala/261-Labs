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
#include "Triangle.h"

Triangle::Triangle(){
  // initializing number of vertices
  numVertices = 3;
  
}

Triangle::~Triangle(){
  return;
}

void Triangle::setColor(const int r, const int g, const int b){
  // Color objects r g and b values
  mColor.r = r;
  mColor.g = g;
  mColor.b = b;
}

void Triangle::draw(RenderTarget& window){
  // Created a convexshape and draws each triangle based on the vertice list
  ConvexShape firstTriangle;
  firstTriangle.setPointCount(numVertices);
  firstTriangle.setPoint(0, Vector2f(verticeList.at(0),verticeList.at(1)));
  firstTriangle.setPoint(1, Vector2f(verticeList.at(2),verticeList.at(3)));
  firstTriangle.setPoint(2, Vector2f(verticeList.at(4),verticeList.at(5)));
  firstTriangle.setFillColor(mColor);
  window.draw(firstTriangle);
}
