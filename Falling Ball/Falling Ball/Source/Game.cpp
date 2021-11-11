// Authors: Zhongbo Sun,
// Assignment Title: Group project
// Assignment Description: Game: Falling ball
// Due Date: 12/8/2020
// Date Created: 11/10/2020
// Date Last Modified: 11/10/2020

#include "Game.h"


void game::init(){
    gameOverStatus=false;
}

void game::play(){
    SDL_Plotter screen(WINDOW_X_SIZE,WINDOW_Y_SIZE);
    startingScreen(screen);
}

void game::update(){
    
    
    //When need to write end game
    //if(){
    //    gameOverStatus=true;
    //}
}

bool game::over(){
    return gameOverStatus;
}

