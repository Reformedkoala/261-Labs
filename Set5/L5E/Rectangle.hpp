#include <iostream>
using namespace std;
class Rectangle {
  private:
    float mBase;
    float mHeight;
  public:
    Rectangle();
    Rectangle(const float BASE, const float HEIGHT);
    float getBase();
    float getHeight();
    void setBase(const float VALUE);
    void setHeight(const float VALUE);
    bool operator<(const Rectangle& OTHER){
      return (mBase < OTHER.mBase)
      || (mBase == OTHER.mBase && mHeight < OTHER.mHeight);
    }
    bool operator>(const Rectangle& OTHER){
      return (mBase > OTHER.mBase)
      || (mBase == OTHER.mBase && mHeight > OTHER.mHeight);
    }
};


Rectangle::Rectangle(){
    mBase = 1;
    mHeight = 1;
}


Rectangle::Rectangle(const float BASE, const float HEIGHT){
  mBase = BASE;
  mHeight = HEIGHT;
}


float Rectangle::getBase(){
    return mBase;
}


float Rectangle::getHeight(){
    return mHeight;
}


void Rectangle::setBase(const float VALUE){
    mBase = VALUE;
}


void Rectangle::setHeight(const float VALUE){
    mHeight = VALUE;
}