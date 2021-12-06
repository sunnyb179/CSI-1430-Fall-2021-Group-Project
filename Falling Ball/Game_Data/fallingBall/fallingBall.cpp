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
