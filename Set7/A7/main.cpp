/* CSCI 261: Assignment 7: A7 - Triangle Land
 *
 * Garrett Thompson
 * 
 * This assignment is meant to practice polymorphism and inheritance of classes as well as virtual functions.  The assignment allows us to draw the c++ logo in SFML through 
 * triangles.
 * 
 */
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
using namespace sf;
using namespace std;
#include "Triangle.h"
#include "ScaleneTriangle.h"
#include "EquilateralTriangle.h"
#include "IsoscelesTriangle.h" 

int main(int argc, char* argv[]) {

    /////////////////////////////////////
    // BEGIN ANY FILE LOADING
    
    string filename;
    if(argc == 1) {
        cout << "Please enter the name for your file here: ";
        getline(cin, filename);
        cout << "Opening file '" << filename << "'" << endl;
    } else if(argc == 2) {
        filename = argv[1];
        cout << "Opening file '" << filename << "'" << endl;
    } else {
        cerr << "Usage: " << argv[0] << " [filename]" << endl;
        cerr << "  filename   - optional file to open upon start" << endl;
        return -2;
    }
    // open file for parsing
    ifstream fileIn;
    fileIn.open(filename);
    if (fileIn.fail()) {
        cerr << "Error opening input file";
        return -1;
    }
    cout << "File opened successfully" << endl;
    
    //Initializing all variables I need for the file reading
    vector<Triangle*> TriangleList;
    char triangleType;
    double x1;  
    double y1; 
    double x2;
    double y2;
    double x3;
    double y3;
    int r;
    int g; 
    int b;
    while(true){
        // Reading in the file(inefficient maybe but easy)
        fileIn >> triangleType;
        fileIn >> x1;
        fileIn >> y1;
        fileIn >> x2;
        fileIn >> y2;
        fileIn >> x3;
        fileIn >> y3;
        fileIn >> r;
        fileIn >> g;
        fileIn >> b;
        // Runtime polymorphism to help determine if scalene, equilateral, or isosceles
        if(triangleType == 'S'){
            ScaleneTriangle* sTriangle;
            sTriangle = new ScaleneTriangle;
            Triangle* pBaseTriangle = &*sTriangle;
            if (pBaseTriangle->setCoordinates(x1, y1, x2, y2, x3, y3) == true){
               pBaseTriangle->setColor(r,g,b);
               TriangleList.push_back(pBaseTriangle);
            }else {
                cout << "Triangle is invalid - " << triangleType << " " << x1 << " " <<  y1 << " " << x2 << " " <<  y2 << " " <<  x3 << " " << y3 << endl;
            }

        }else if(triangleType == 'I'){
            IsoscelesTriangle* iTriangle;
            iTriangle = new IsoscelesTriangle;
            Triangle* pBaseTriangle = &*iTriangle;
            if (pBaseTriangle->setCoordinates(x1, y1, x2, y2, x3, y3) == true){
                pBaseTriangle->setColor(r,g,b);
                TriangleList.push_back(pBaseTriangle);
            }else {
                cout << "Triangle is invalid - " << triangleType << " " << x1 << " " <<  y1 << " " << x2 << " " <<  y2 << " " <<  x3 << " " << y3 << endl;
            }

        } else if(triangleType == 'E'){
            EquilateralTriangle* eTriangle;
            eTriangle = new EquilateralTriangle;
            Triangle *pBaseTriangle = &*eTriangle;
            if (pBaseTriangle->setCoordinates(x1, y1, x2, y2, x3, y3) == true){
                pBaseTriangle->setColor(r,g,b);
                TriangleList.push_back(pBaseTriangle);
            }else {
                cout << "Triangle is invalid - " << triangleType << " " << x1 << " " <<  y1 << " " << x2 << " " <<  y2 << " " <<  x3 << " " << y3 << " " << r << " " << g << " " << b << endl;
            }

        } 
        if( fileIn.eof() ) break;
    }
    
    //  END  ANY FILE LOADING
    /////////////////////////////////////
    
    // create a window
    RenderWindow window( VideoMode(640, 640), "SFML Test" );

    // create an event object once to store future events
    Event event;

    // while the window is open
    while( window.isOpen() ) {
        // clear any existing contents
        window.clear();

        /////////////////////////////////////
        // BEGIN DRAWING HERE
        // Drawing all triangles
        for(int i = 0; i < TriangleList.size(); i++){
            TriangleList.at(i)->draw(window);
        }
        //  END  DRAWING HERE
        /////////////////////////////////////


        // display the current contents of the window
        window.display();

        /////////////////////////////////////
        // BEGIN EVENT HANDLING HERE
        // check if any events happened since the last time checked
        while( window.pollEvent(event) ) {
            // if event type corresponds to pressing window X
            if(event.type == Event::Closed) {
                // tell the window to close
                window.close();
            }
            // check addition event types to handle additional events
        }
        //  END  EVENT HANDLING HERE
        /////////////////////////////////////
    }

    return 0;
}