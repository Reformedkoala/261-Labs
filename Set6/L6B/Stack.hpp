#include <vector>
#include <iostream>
using namespace std;

/**
 * @brief Stack object
 * 
 */
template<typename T>
class Stack {
  public:
    Stack();
    ~Stack();
    Stack(const Stack& OTHER);
    void push(const T VAR);
    T peak();
    T pop();
    bool isEmpty();
  private:
    vector<T> mStack;
};


template<typename T>
Stack<T>::Stack(){
  vector<T> mStack;
}


template<typename T>
Stack<T>::~Stack(){
  mStack.clear();
}


template<typename T>
Stack<T>::Stack(const Stack& OTHER){
  this->mStack = OTHER.mStack;
}


template<typename T>
void Stack<T>::push(const T VAR){
  mStack.push_back(VAR);
}


template<typename T>
T Stack<T>::peak(){
  return mStack.back();
}

template<typename T>
T Stack<T>::pop(){
  T tempVar = mStack.back();
  mStack.pop_back();
  return tempVar;
}

template<typename T>
bool Stack<T>::isEmpty(){
  if(mStack.size() == 0){return true;}
  else{return false;}
}