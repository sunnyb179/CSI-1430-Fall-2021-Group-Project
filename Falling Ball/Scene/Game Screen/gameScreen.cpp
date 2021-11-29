//
//  gameScreen.cpp
//  Falling Ball
//
//  Created by Zhongbo Sun on 11/28/21.
//

#include "gameScreen.h"

int gameScreen(SDL_Plotter& screen){
    //Data Abstraction
    bool notSelect=true;
    
    //Window drawing
    drawBackground(WINDOW_Y_SIZE,WINDOW_X_SIZE,gBACKGROUND_COLOR_R,gBACKGROUND_COLOR_G+100,gBACKGROUND_COLOR_B,screen);
    screen.update();
    
    
    //Waiting for action
    while(notSelect)
    {
        if(screen.getQuit())
        {
            notSelect=false;
        }
        
        if(screen.kbhit())
        {
            screen.getKey();
        }
    }
    
    return 1;
}
