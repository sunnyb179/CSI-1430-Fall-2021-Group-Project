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
    
        drawBackground(WINDOW_Y_SIZE,WINDOW_X_SIZE,254,155,66,screen);
        drawButton(175,450,100,40,100,100,100, screen);
        screen.update();
    }
}
