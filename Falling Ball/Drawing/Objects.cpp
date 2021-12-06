//
//  Objects.cpp
//  Falling Ball
//
//  Created by Zhongbo Sun on 11/10/21.
//

#include "Objects.h"

void plotPoint(int X,int Y,int R,int G,int B,SDL_Plotter& screen){
    if(X>=0&&X<WINDOW_X_SIZE&&Y>=0&&Y<WINDOW_Y_SIZE)
    {
        screen.plotPixel(X,Y,R,G,B);
    }
}
void drawRectangle(int centerX,int centerY,int sizeX,int sizeY,int R,int G,int B,SDL_Plotter& screen){
    for(int x=centerX-sizeX;x<centerX+sizeX;x++)
    {
        for(int y=centerY-sizeY;y<centerY+sizeY;y++)
        {
            plotPoint(x, y, R, G, B,screen);
        }
    }
}

void drawBackground(int sizeX,int sizeY,int R,int G,int B,SDL_Plotter& screen){
    for(int x=0;x<sizeX;x++)
    {
        for(int y=0;y<sizeY;y++)
        {
            plotPoint(x, y, R, G, B,screen);
        }
    }
}

void drawButton(int centerX,int centerY,int sizeX,int sizeY,int R,int G,int B,SDL_Plotter& screen){
    for(int x=centerX-sizeX;x<centerX+sizeX;x++)
    {
        for(int y=centerY-sizeY;y<centerY+sizeY;y++)
        {
            plotPoint(x, y, R, G, B,screen);
        }
    }
}

void drawCircle(int centerX,int centerY,int radius,int R,int G,int B,SDL_Plotter& screen){
    int loopTimes=0;
    while(radius>=0)
    {
        loopTimes++;
        for (double angle=0; angle<=2*PI; angle+=0.01)
        {
            plotPoint(centerX+round(radius*cos(angle)), centerY+round(radius*sin(angle)), R, G, B,screen);
        }
        if(loopTimes==1)
        {
            R+=0;
        }
        radius--;
    }
}

void drawTriangle(int centerX,int centerY,int height, int R, int G, int B, SDL_Plotter& screen){
    double xchange=0;
    centerY+=gTRIANGLE_HIEHGT/2;
    for (int y=centerY-height;y<centerY;y++){
        for (double x=centerX;x<=centerX+xchange;x+=1){
            plotPoint(round(x), y, R, G, B,screen);
        }
        xchange+=0.6;
    }
    xchange=0;
    for (int y=centerY-height;y<centerY;y++){
        for (double x=centerX;x>=centerX-xchange;x-=1){
            plotPoint(round(x), y, R, G, B,screen);
        }
        xchange+=0.6;
    }
}

void drawBallAdder(int centerX,int centerY,SDL_Plotter& screen){
    drawCircle(centerX,centerY,gBAll_ADDER_RADIUS,gBAll_ADDER_R,gBAll_ADDER_G,gBAll_ADDER_B,screen);
    drawCircle(centerX,centerY,round(gBAll_ADDER_RADIUS*0.9),gBACKGROUND_COLOR_R,gBACKGROUND_COLOR_G,gBACKGROUND_COLOR_B,screen);
    drawCircle(centerX,centerY,round(gBAll_ADDER_RADIUS*0.6),gBAll_ADDER_R,gBAll_ADDER_R,gBAll_ADDER_R,screen);
}
