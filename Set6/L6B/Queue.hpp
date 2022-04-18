#include <vector>
#include <iostream>
using namespace std;

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


template<typename T>
Queue<T>::Queue(){
  vector<T> mQueue;
}


template<typename T>
Queue<T>::~Queue(){
  mQueue.clear();
}


template<typename T>
Queue<T>::Queue(const Queue& OTHER){
  this->mQueue = OTHER.mQueue;
}


template<typename T>
void Queue<T>::push(const T VAR){
  mQueue.push_back(VAR);
}


template<typename T>
T Queue<T>::peak(){
  return mQueue.front();
}

template<typename T>
T Queue<T>::pop(){
  T tempVar = mQueue.front();
  mQueue.erase(mQueue.begin());
  return tempVar;
}

template<typename T>
bool Queue<T>::isEmpty(){
  if(mQueue.size() == 0){return true;}
  else{return false;}
}