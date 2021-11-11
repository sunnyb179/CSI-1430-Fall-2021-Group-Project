//
//  startingScreen.cpp
//  Falling Ball
//
//  Created by Zhongbo Sun on 11/10/21.
//

#include "startingScreen.h"

void startingScreen(SDL_Plotter& screen){
    while(!screen.getQuit()){
        if(screen.kbhit())
        {
            screen.getKey();
        }
    
        drawBackground(WINDOW_X_SIZE,WINDOW_Y_SIZE,254,155,66,screen);
        drawButton(500,125,30,70,100,100,100, screen);
        screen.update();
    }
}
