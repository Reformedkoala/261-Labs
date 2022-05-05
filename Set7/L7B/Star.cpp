/* CSCI 261: Lab 7B - Starcraft
 *
 * Author: Garrett Thompson
 *
 * This lab is meant to help practice inheritance and the use of classes when interacting with objects. This program takes a list of star coordinates and brightness in order
 * to draw them on a star chart using SFML
 * 
 */
#include <SFML/Graphics.hpp>
using namespace sf;
#include "Star.h"

// Star overloaded constructor implementation to set everything needed
Star::Star(int windowWidth, int windowHeight, float maxBrightness){
  mWindowWidth = windowWidth;
  mWindowHeight = windowHeight;
  mMaxBrightness = maxBrightness;
  CircleShape::setRadius(2.0);
  CircleShape::setPosition(0.0f ,0.0f);
  setBrightness(maxBrightness/2); 
}

// setPosition function to call the circleshape position function once we normalize the x and y value coordinates
void Star::setPosition(float xPos, float yPos){
  float xPixel;
  float yPixel;
  xPixel = ( xPos + 1.0 ) * mWindowWidth / 2.0;
  yPixel = ( yPos + 1.0 ) * mWindowHeight / 2.0;
  CircleShape::setPosition(xPixel, yPixel);
}

// setBrightness function to determine the shade of grey and brightness of the star on the map
void Star::setBrightness(float brightness){
  float invertedBrightness = 8.0 - brightness;
  int shadeOfGray = (int)( ( 255.0 * brightness ) / invertedBrightness );
  setFillColor( Color(shadeOfGray, shadeOfGray, shadeOfGray) );
}