//
//  startingScreen.cpp
//  Falling Ball
//
//  Created by Zhongbo Sun on 11/10/21.
//

#include "startingScreen.h"

int startingScreen(SDL_Plotter& screen){
    //Data Abstraction
    bool notSelect=true;
    int nextScreen=0,mouseX=0,mouseY=0;
    
    //Window drawing
    drawBackground(WINDOW_X_SIZE,WINDOW_Y_SIZE,sBACKGROUND_COLOR_R,sBACKGROUND_COLOR_G,sBACKGROUND_COLOR_B,screen);
    drawButton(sGAME_BUTTON_CENTER_X,sGAME_BUTTON_CENTER_Y,sGAME_BUTTON_SIZE_X,sGAME_BUTTON_SIZE_Y,sGAME_BUTTON_COLOR_R,sGAME_BUTTON_COLOR_G,sGAME_BUTTON_COLOR_B, screen);
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
        
        if(screen.getMouseClick(mouseX,mouseY))
        {
            if(mouseX<sGAME_BUTTON_CENTER_X+sGAME_BUTTON_SIZE_X&&mouseX>sGAME_BUTTON_CENTER_X-sGAME_BUTTON_SIZE_X&&mouseY<sGAME_BUTTON_CENTER_Y+sGAME_BUTTON_SIZE_Y&&mouseY>sGAME_BUTTON_CENTER_Y-sGAME_BUTTON_SIZE_Y)
            {
                screen.initSound("mixkit-arcade-game-opener-222.wav");
                screen.playSound("mixkit-arcade-game-opener-222.wav");
                notSelect=false;
                nextScreen=1;
            }
        }
        else if(screen.getKey()=='q')
        {
            notSelect=false;
            nextScreen=-1;
        }
    }
    
    return nextScreen;
}
