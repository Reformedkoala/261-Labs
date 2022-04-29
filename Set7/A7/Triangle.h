#ifndef TRIANGLE_H
#define TRIANGLE_H
#include <SFML/Graphics.hpp>
#include <vector>
using namespace sf;
using namespace std;

class Triangle : public ConvexShape {
  public:
    Triangle();
    virtual ~Triangle();
    void setColor(const int r, const int g, const int b);
    void draw(RenderTarget& window);
    virtual bool setCoordinates(double x1, double y1, double x2, double y2, double x3, double y3) = 0;

  protected:
    int numVertices;
    vector<float> verticeList;
    
  private:
    Color mColor;

}; 

#endif