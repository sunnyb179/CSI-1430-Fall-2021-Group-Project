//
//  gameObjectStatus.cpp
//  Falling Ball
//
//  Created by Zhongbo Sun on 12/4/21.
//

#include "gameObjectStatus.h"




void PositionStatus::drawObject(SDL_Plotter& screen){
    //shift color based on life
    if(R+objectLife*10<255)
    {
        R=gOBJECT_R+(objectLife%8*10);
    }
    if(G+objectLife*10<255)
    {
        R=gOBJECT_G-objectLife%25*10;
    }
    if(B+objectLife*10<255)
    {
        B=gOBJECT_B-objectLife%15*10;
    }
    
    if(objectType==0){
        drawRectangle(centerX, centerY, gSQUAR_SIDE, gSQUAR_SIDE, R, G, B, screen);
    }
    else if(objectType==1){
        drawTriangle(centerX,centerY,gTRIANGLE_HIEHGT, R, G, B, screen);
    }
    else if(objectType==2){
        drawCircle(centerX, centerY, gOBJECT_BALL_RADIUS, R, G, B, screen);
    }
    else if(objectType==3){
        drawBallAdder(centerX,centerY,screen);
    }
    
    if(objectType!=-1&&objectType!=3)
    {
        if(objectLife<10)
        {
            plotChar(centerX-gOBJECT_LIFE_FONT_SIZE*1, centerY-gOBJECT_LIFE_FONT_SIZE, static_cast<char>(objectLife)+'0', gOBJECT_LIFE_FONT_SIZE,255,255,255,screen);
        }
        else
        {
            plotInt(objectLife,gOBJECT_LIFE_FONT_SIZE-2,centerX-gOBJECT_LIFE_FONT_SIZE-4,centerY,255,255,255,screen);
        }
    }
}
