#ifndef EQUILATERALTRIANGLE_H
#define EQUILATERALTRIANGLE_H
#include <SFML/Graphics.hpp>
#include <vector>
#include "Triangle.h"
using namespace sf;
using namespace std;

class EquilateralTriangle: public Triangle{
  public:
    bool setCoordinates(double x1, double y1, double x2, double y2, double x3, double y3);
};
#endif