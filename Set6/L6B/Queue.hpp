#include <vector>
#include <iostream>
using namespace std;
/* CSCI 261: Lab 6B - Processing Ordered Lists
 *
 * Author: Garrett Thompson
 * 
 * This program allows me to experiment with the stack and queue data structure and to test my templated class implementation of them
 * 
 */
/**
 * @brief Queue object
 * 
 */
template<typename T>
class Queue {
  public:
    Queue();
    ~Queue();
    Queue(const Queue& OTHER);
    void push(const T VAR);
    T peak();
    T pop();
    bool isEmpty();
  private:
    vector<T> mQueue;
};

/**
 * @brief Queue default constructor
 * 
 */
template<typename T>
Queue<T>::Queue(){
  vector<T> mQueue;
}

/**
 * @brief Default destructor
 * 
 */
template<typename T>
Queue<T>::~Queue(){
  mQueue.clear();
}

/**
 * @brief Queue copy constructor
 *  
 * @param OTHER queue to copy
 */
template<typename T>
Queue<T>::Queue(const Queue& OTHER){
  this->mQueue = OTHER.mQueue;
}

/**
 * @brief method to push to the back of the queue
 * 
 * @param vAR variable to push to the queue
 * 
 */
template<typename T>
void Queue<T>::push(const T VAR){
  mQueue.push_back(VAR);
}

/**
 * @brief method to peak to the front of the queue and get the value at it
 * 
 */
template<typename T>
T Queue<T>::peak(){
  return mQueue.front();
}


/**
 * @brief method to pop the front of the queue
 * 
 */
template<typename T>
T Queue<T>::pop(){
  T tempVar = mQueue.front();
  mQueue.erase(mQueue.begin());
  return tempVar;
}

/**
 * @brief method to check if the queue is empty
 * 
 */
template<typename T>
bool Queue<T>::isEmpty(){
  if(mQueue.size() == 0){return true;}
  else{return false;}
}