//
//  Objects.cpp
//  Falling Ball
//
//  Created by Zhongbo Sun on 11/10/21.
//

#include "Objects.h"

void drawBackground(int sizeX,int sizeY,int R,int G,int B,SDL_Plotter& screen){
    for(int x=0;x<sizeX;x++)
    {
        for(int y=0;y<sizeY;y++)
        {
            screen.plotPixel(x, y, R, G, B);
        }
    }
}

void drawButton(int centerX,int centerY,int sizeX,int sizeY,int R,int G,int B,SDL_Plotter& screen){
    for(int x=centerX-sizeX;x<centerX+sizeX;x++)
    {
        for(int y=centerY-sizeY;y<centerY+sizeY;y++)
        {
            screen.plotPixel(x, y, R, G, B);
        }
    }
}
