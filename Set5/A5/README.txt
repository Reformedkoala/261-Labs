1. How did you structure your Player?
    I structured my player as a class which may not have been the best choice as I probably should've just made it a struct because I didn't even need the getters and setters, 
    but it was already implemented and I didn't want to change it.  This did allow me however to keep the player as an object inside of the linked list which game me direct access to the data members still.
2. How did you structure your Game?
    I structured the game as a class so that I could call a member function to perform a turn and check if the game was over or not all inside of main.  This also allowed me to
    construct the game based on user parameters and take in input that way.
3. How did you make use of classes and functions? What went where?
    I made use of the classes that I used to just structure the logic and hold each parameter I needed to keep track of in the implementation of the game.  I didn't need all of
    the functions I made, but it was good practice and I could've used them I just ran into implementation problems with setters and copies being created.  I had to change around
    how I was accessing some of the objects in the linked list and how I changed them which made some of the functions I implemented useless.  Other then that the implementations
    I used worked fine and allowed me to control the game state at all times once I got past changing the chip numbers of each player.