#include <SFML/Graphics.hpp>
using namespace sf;
#include "EquilateralTriangle.h"
#include <cmath>
#include <iostream>
bool EquilateralTriangle::setCoordinates(float x1, float y1, float x2, float y2, float x3, float y3){
  double d1 = sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
  double d2 = sqrt((x3-x2)*(x3-x2) + (y3-y2)*(y3-y2));
  double d3 = sqrt((x1-x3)*(x1-x3) + (y1-y3)*(y1-y3));
  if(d1 > 0 && d2 > 0 && d3 > 0 && ( d1+d2 >= d3 || d2+d3 >= d1 || d1+d3 >= d2 ) && d1 == d2 ){
    verticeList.push_back(x1);
    verticeList.push_back(y1);
    verticeList.push_back(x2);
    verticeList.push_back(y2);
    verticeList.push_back(x3);
    verticeList.push_back(y3);
    return true;
  }
  else{
    cout << d1 << " " << d2 << " " << d3 << endl;
    return false;
  }
}