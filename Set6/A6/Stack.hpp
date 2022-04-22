#include <vector>
#include <iostream>
using namespace std;
/* CSCI 261: Assignment 6: A6 - A-MAZE-ing
 *
 * Author: Garrett Thompson
 * 
 * This program allows the user to solve a text maze file
 * This stores the Stack class for the program to use 
 * 
 */
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

/**
 * @brief Default stack constructor
 * 
 */
template<typename T>
Stack<T>::Stack(){
  vector<T> mStack;
}


/**
 * @brief default stack destructor
 * 
 */
template<typename T>
Stack<T>::~Stack(){
  mStack.clear();
}


/**
 * @brief Default copy constructor for the stack object
 * 
 * @param OTHER Stack object to copy
 */
template<typename T>
Stack<T>::Stack(const Stack& OTHER){
  this->mStack = OTHER.mStack;
}


/**
 * @brief method to push to the back of the stack
 * 
 * @param VAR to push to the back of the Stack
 * 
 */
template<typename T>
void Stack<T>::push(const T VAR){
  mStack.push_back(VAR);
}


/**
 * @brief method to return the back of the stack
 * 
 */
template<typename T>
T Stack<T>::peak(){
  return mStack.back();
}


/**
 * @brief method to pop the back of the stack and return the value
 * 
 */
template<typename T>
T Stack<T>::pop(){
  T tempVar = mStack.back();
  mStack.pop_back();
  return tempVar;
}

/**
 * @brief method to check if the stack is empty
 * 
 */
template<typename T>
bool Stack<T>::isEmpty(){
  if(mStack.size() == 0){return true;}
  else{return false;}
}