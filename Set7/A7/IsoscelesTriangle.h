#ifndef ISOSCELESTRIANGLE_H
#define ISOSCELESTRIANGLE_H
#include <SFML/Graphics.hpp>
#include <vector>
#include "Triangle.h"
using namespace sf;
using namespace std;

class IsoscelesTriangle: public Triangle{
  public:
    bool setCoordinates(float x1, float y1, float x2, float y2, float x3, float y3);
};
#endif