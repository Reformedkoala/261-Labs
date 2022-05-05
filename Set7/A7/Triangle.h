/* CSCI 261: Assignment 7: A7 - Triangle Land
 *
 * Garrett Thompson
 * 
 * This assignment is meant to practice polymorphism and inheritance of classes as well as virtual functions.  The assignment allows us to draw the c++ logo in SFML through 
 * triangles.
 * 
 */
#ifndef TRIANGLE_H
#define TRIANGLE_H
#include <SFML/Graphics.hpp>
#include <vector>
using namespace sf;
using namespace std;

class Triangle : public ConvexShape {
  public:
    /**
    * @brief default constructor for the triangle class
    * 
    * 
    */
    Triangle();
    /**
    * @brief virtual destructor so it can clean up the class
    * 
    * 
    */
    virtual ~Triangle();
    /**
    * @brief setColor method to set the color of each triangle based on r g and b values
    * 
    * @param r red color code
    * @param g green color code
    * @param b blue color code
    * 
    */
    void setColor(const int r, const int g, const int b);
    /**
    * @brief draw method to call the draw shape function to draw in the proper window once we have the correct triangle
    * 
    * @param window window object passed by reference so we don't create more then one and it draws to the proper one
    * 
    */
    void draw(RenderTarget& window);
    /**
    * @brief virtual setCoordinates for each triangle to determine it's position
    * 
    * @param x1
    * @param y1
    * @param x2
    * @param y2
    * @param x3
    * @param y3
    * 
    */
    virtual bool setCoordinates(double x1, double y1, double x2, double y2, double x3, double y3) = 0;

  protected:
    /**
    * @brief numVertices for the convexshape class
    * 
    * 
    */
    int numVertices;
    /**
    * @brief vertice list to use in the class and store the x and y values
    * 
    * 
    */
    vector<float> verticeList;
    
  private:
    /**
    * @brief private color object created to use later
    */
    Color mColor;

}; 

#endif