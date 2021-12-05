//
//  gameObjectStatus.cpp
//  Falling Ball
//
//  Created by Zhongbo Sun on 12/4/21.
//

#include "gameObjectStatus.h"




void PositionStatus::drawObject(SDL_Plotter& screen){
    if(objectType==0){
        drawRectangle(centerX, centerY, gSQUAR_SIDE, gSQUAR_SIDE, gSQUAR_R, gSQUAR_G, gSQUAR_B, screen);
    }
    else if(objectType==1){
        drawTriangle(centerX,centerY,gTRIANGLE_HIEHGT, gTRIANGLE_R, gTRIANGLE_G, gTRIANGLE_B, screen);
    }
    else if(objectType==2){
        drawCircle(centerX, centerY, gOBJECT_BALL_RADIUS, gOBJECT_BALL_R, gOBJECT_BALL_G, gOBJECT_BALL_B, screen);
    }
}
