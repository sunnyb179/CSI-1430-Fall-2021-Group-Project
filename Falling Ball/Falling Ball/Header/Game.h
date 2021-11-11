// Authors: Zhongbo Sun,
// Assignment Title: Group project
// Assignment Description: Game: Falling ball
// Due Date: 12/8/2020
// Date Created: 11/10/2020
// Date Last Modified: 11/10/2020

#ifndef Game_h
#define Game_h


//#include "SDL_Tester.h"
//Library Above is test stuff.

#include "startingScreen.h"
#include "Data.h"


class game{
private:
    bool gameOverStatus;    //To see if the game end or not
    
public:
    void init();            //Set data inplace for the game
    void play();            //Open up window, draw stuff
    void update();          //Update each status
    bool over();            //end the program
};

#endif /* Game_h */
