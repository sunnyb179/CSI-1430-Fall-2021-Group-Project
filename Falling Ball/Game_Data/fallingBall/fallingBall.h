//
//  fallingBall.h
//  Falling Ball
//
//  Created by Zhongbo Sun on 12/5/21.
//

#ifndef fallingBall_h
#define fallingBall_h

#include "Objects.h"
#include "Data.h"

struct fallingBall{
    int centerX=WINDOW_X_SIZE/2;
    int centerY=50;
    double volcityY;
    double volcityX;
    void drawBall(SDL_Plotter& screen);
};

#endif /* fallingBall_h */
