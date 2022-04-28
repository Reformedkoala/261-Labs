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
    virtual bool setCoordinates(float x1, float y1, float x2, float y2, float x3, float y3) = 0;

  protected:
    int numVertices;
    vector<float> verticeList;
    
  private:
    Color mColor;

}; 

#endif