#include <SFML/Graphics.hpp>
using namespace sf;
#include "Triangle.h"

Triangle::Triangle(){
  numVertices = 3;
  
}

Triangle::~Triangle(){
  return;
}

void Triangle::setColor(const int r, const int g, const int b){
  mColor.r = r;
  mColor.g = g;
  mColor.b = b;
}

void Triangle::draw(RenderTarget& window){
  ConvexShape firstTriangle;
  firstTriangle.setPointCount(numVertices);
  firstTriangle.setPoint(0, Vector2f(verticeList.at(0),verticeList.at(1)));
  firstTriangle.setPoint(1, Vector2f(verticeList.at(2),verticeList.at(3)));
  firstTriangle.setPoint(2, Vector2f(verticeList.at(4),verticeList.at(5)));
  firstTriangle.setFillColor(mColor);
  window.draw(firstTriangle);
}
