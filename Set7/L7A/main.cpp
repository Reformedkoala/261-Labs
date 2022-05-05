/* CSCI 261: Lab 7A - SFML Drawing
 *
 * Author: Garrett Thompson
 *
 * This lab is meant to help get a grasp on the SFML graphics library and start to understand what we can do with it.
 * 
 */

#include <SFML/Graphics.hpp>
using namespace sf;

int main() {
    // create a window
    RenderWindow window( VideoMode(1920, 1080), "SFML Test" );

    /////////////////////////////////////
    // BEGIN ANY FILE LOADING

    // perform any file processing once before draw loop begins

    //  END  ANY FILE LOADING
    /////////////////////////////////////

    // create an event object once to store future events
    Event event;

    // while the window is open
    while( window.isOpen() ) {
        // clear any existing contents
        window.clear();

        /////////////////////////////////////
        // BEGIN DRAWING HERE

        RectangleShape rect5;
        rect5.setSize( Vector2f( 1920, 1080 ) );
        rect5.setPosition( 0, 0 );
        rect5.setFillColor( Color(135,206,235));
        window.draw( rect5 );

        CircleShape star;
        star.setPosition( 880, 350 );
        star.setRadius(100 );
        star.setFillColor( Color::Green );
        window.draw( star);
        
        RectangleShape rect;
        rect.setSize( Vector2f( 45, 150 ) );
        rect.setPosition( 960, 500 );
        rect.setFillColor( Color(165,42,42));
        window.draw( rect );

        CircleShape star2;
        star2.setPosition( 1080, 350 );
        star2.setRadius(100 );
        star2.setFillColor( Color::Green );
        window.draw( star2);

        RectangleShape rect2;
        rect2.setSize( Vector2f( 45, 150 ) );
        rect2.setPosition( 1160, 500 );
        rect2.setFillColor( Color(165,42,42));
        window.draw( rect2 );

        CircleShape star3;
        star3.setPosition( 680, 350 );
        star3.setRadius(100 );
        star3.setFillColor( Color::Green );
        window.draw( star3 );
        
        RectangleShape rect3;
        rect3.setSize( Vector2f( 45, 150 ) );
        rect3.setPosition( 760, 500 );
        rect3.setFillColor( Color(165,42,42));
        window.draw( rect3 );

        RectangleShape rect4;
        rect4.setSize( Vector2f( 1920, 500 ) );
        rect4.setPosition( 0, 1080-450 );
        rect4.setFillColor( Color(0,177,64));
        window.draw( rect4 );

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