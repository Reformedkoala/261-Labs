/* CSCI 261: Lab 5E - Procedural and Object-Oriented
 *
 * Author: Garrett Thompson
 *
 * Rectangle class declaration and implementation file for the objects we use during the lab
 * 
 */

#include <iostream>
using namespace std;

class Rectangle {
  private:
    /**
     * @brief The private data member for the base of the rectangle
     * 
     */
    float mBase;
    /**
     * @brief The private data member for the height of the rectangle
     * 
     */
    float mHeight;
  public:
    /**
     * @brief The default constructor for the class
     * 
     */
    Rectangle();
    /**
     * @brief Overloaded constructor for the rectangle class
     * 
     * @param BASE Provided base value for the rectangle to create
     * 
     * @param HEIGHT Provided height value for the rectangle to create
     * 
     */
    Rectangle(const float BASE, const float HEIGHT);
    /**
     * @brief Getter for the rectangle base
     * 
     */
    float getBase();
    /**
     * @brief Getter for the rectangle height
     * 
     */
    float getHeight();
    /**
     * @brief Setter for the rectangle base
     * 
     * @param VALUE value to set the base to 
     * 
     */
    void setBase(const float VALUE);
    /**
     * @brief Setter for the rectangle height
     * 
     * @param VALUE to set the height to
     * 
     */
    void setHeight(const float VALUE);
    /**
     * @brief overloaded operator for the < compare operation
     * 
     * @param OTHER object passed in to compare to the callee
     * 
     */
    bool operator<(const Rectangle& OTHER){
      return (mBase < OTHER.mBase)
      || (mBase == OTHER.mBase && mHeight < OTHER.mHeight);
    }
    /**
     * @brief overloaded operator for the > compare operation
     * 
     * @param OTHER object passed in to compare to the callee
     * 
     */
    bool operator>(const Rectangle& OTHER){
      return (mBase > OTHER.mBase)
      || (mBase == OTHER.mBase && mHeight > OTHER.mHeight);
    }
};


Rectangle::Rectangle(){
  // Default constructor
    mBase = 1;
    mHeight = 1;
}


Rectangle::Rectangle(const float BASE, const float HEIGHT){
  // Overloaded constructor
  mBase = BASE;
  mHeight = HEIGHT;
}


float Rectangle::getBase(){
  // Returning the base
    return mBase;
}


float Rectangle::getHeight(){
  // Returning the height
    return mHeight;
}


void Rectangle::setBase(const float VALUE){
  // Setting the base
    mBase = VALUE;
}


void Rectangle::setHeight(const float VALUE){
  // Setting the height
    mHeight = VALUE;
}