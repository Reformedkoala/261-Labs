#ifndef STAR_H
#define STAR_H
#include <SFML/Graphics.hpp>
using namespace sf;

class Star : public CircleShape {
  public:
    Star(int windowWidth, int windowHeight, float maxBrightness);
    void setPosition(float xPos, float yPos);
    void setBrightness(float brightness);
  private:
    int mWindowWidth;
    int mWindowHeight;
    float mMaxBrightness;
}; 

#endif