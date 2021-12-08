//
//  fallingBall.cpp
//  Falling Ball
//
//  Created by Zhongbo Sun on 12/5/21.
//

#include "fallingBall.h"

void fallingBall::drawBall(SDL_Plotter& screen){
    drawCircle(round(centerX), round(centerY), gSMALL_BALL_RADIUS, gSMALL_BAll_R, gSMALL_BAll_G, gSMALL_BAll_B, screen);
}

double fallingBall::totalVolcity(){
    return sqrt(pow(volcityX,2)+pow(volcityY,2));
}

double fallingBall::getVolcityAngle(){
    double ans=INFINITY;
    if(volcityX>0&&volcityY>0)
    {
        ans=atan(volcityY/volcityX);
    }
    else if(volcityX>0&&volcityY<0)
    {
        ans=2*PI+atan(volcityY/volcityX);
    }
    else if(volcityX<0&&volcityY<0)
    {
        ans=PI+atan(volcityY/volcityX);
    }
    else if(volcityX<0&&volcityY>0)
    {
        ans=PI+atan(volcityY/volcityX);
    }
    return ans;
}
