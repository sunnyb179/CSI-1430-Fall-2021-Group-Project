/*
* Author: Zhongbo Sun
          Leyang Zhou
          Shaoyu Chen
          Yian Ge
          Jake Caraway
* Assignment Title: Falling Ball
* File Name: Game.h
* Assignment Description: This file contains and organizes the required constants for the
* Due Date: 12/08/21
* Date Created: 11/10/21
* Date Last Modified: 12/08/21 - 8:31pm
*/

#ifndef Game_h
#define Game_h


//#include "SDL_Tester.h"
//Library Above is test stuff.

#include "startingScreen.h"
#include "gameScreen.h"
#include "leaderboard.h"
#include "Data.h"


class game{
private:
    bool gameOverStatus;    //To see if the game end or not
    int currentScene;
    //currentScene=0 Starting screen
    //currentScene=1 game screen
    //currentScene=2 leader board
    
    
    
    
public:
    void init(SDL_Plotter& screen);            //Set data inplace for the game
    void play(SDL_Plotter& screen);            //Open up window, draw stuff
    void update(SDL_Plotter& screen);          //Update each status
    bool over(SDL_Plotter& screen);            //end the program
};

#endif /* Game_h */
