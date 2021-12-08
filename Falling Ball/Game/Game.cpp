// Authors: Zhongbo Sun,
// Assignment Title: Group project
// Assignment Description: Game: Falling ball
// Due Date: 12/8/2020
// Date Created: 11/10/2020
// Date Last Modified: 11/10/2020

#include "Game.h"


void game::init(SDL_Plotter& screen){
    screen.initSound("Nyan Cat.wav");
    gameOverStatus=false;
    currentScene=0;
}

void game::play(SDL_Plotter& screen){
    
}

void game::update(SDL_Plotter& screen){
    if(currentScene==0)
    {
        currentScene=startingScreen(screen);
    }
    else if(currentScene==1)
    {
        currentScene=gameScreen(screen);
    }
    else if(currentScene==2)
    {
        currentScene=2;
    }
    else if(currentScene==-1)
    {
        
    }
}

bool game::over(SDL_Plotter& screen){
    if(screen.getQuit())
    {
        gameOverStatus=true;
    }
    return gameOverStatus;
}

