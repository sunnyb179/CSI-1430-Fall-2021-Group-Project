//
//  fallingBall.h
//  Falling Ball
//
//  Created by Zhongbo Sun on 12/5/21.
//

#ifndef fallingBall_h
#define fallingBall_h

#include <cmath>
#include "Objects.h"
#include "Data.h"


struct fallingBall{
    double centerX=WINDOW_X_SIZE/2;
    double centerY=gSTART_Height;
    double volcityY;
    double volcityX;
    void drawBall(SDL_Plotter& screen);
    double totalVolcity();
    double getVolcityAngle();
};

#endif /* fallingBall_h */
