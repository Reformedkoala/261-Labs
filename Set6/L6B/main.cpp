#include "Stack.hpp"
#include "Queue.hpp"

#include <iostream>
using namespace std;
/* CSCI 261: Lab 6B - Processing Ordered Lists
 *
 * Author: Garrett Thompson
 * 
 * This program allows me to experiment with the stack and queue data structure and to test my templated class implementation of them
 * 
 */
int main() {
    // Creating the stack object and pushing a list of integers
    Stack<int> stacker;
    stacker.push(1);
    stacker.push(2);
    stacker.push(3);
    stacker.push(4);
    stacker.push(5);
    // Iterating over the stack and popping them after printing them out
    while( !stacker.isEmpty() ) {
        cout << "stack top is: " << stacker.peak() << " \t";
        int top = stacker.pop();
        cout << "stack top was: " << top << endl;
    }
    cout << "stack is empty" << endl;

    cout << endl;
    
    // Creating the queue object to iterate over and empty while printing
    Queue<int> queuer;
    queuer.push(1);
    queuer.push(2);
    queuer.push(3);
    queuer.push(4);
    queuer.push(5);
    while( !queuer.isEmpty() ) {
        cout << "queue front is: " << queuer.peak() << "\t";
        int front = queuer.pop();
        cout << "queue front was: " << front << endl;
    }
    cout << "queue is empty" << endl;
    
    return 0;
}