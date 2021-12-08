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
        R=gOBJECT_R+objectLife*10;
    }
    if(G+objectLife*10<255)
    {
        R=gOBJECT_G-objectLife*10;
    }
    if(B+objectLife*10<255)
    {
        B=gOBJECT_B+objectLife*10;
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
        plotChar(centerX-10, centerY-10, static_cast<char>(objectLife)+'0', 4, screen);
    }
}
