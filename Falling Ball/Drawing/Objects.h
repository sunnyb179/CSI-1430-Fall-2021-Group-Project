//
//  Objects.h
//  Falling Ball
//
//  Created by Zhongbo Sun on 11/10/21.
//

#ifndef Objects_h
#define Objects_h

#include "SDL_Plotter.h"
#include "Data.h"

void drawBackground(int sizeX,int sizeY,int R,int G,int B,SDL_Plotter& screen);

void drawButton(int centerX,int centerY,int sizeX,int sizeY,int R,int G,int B,SDL_Plotter& screen);

//void drawRectangle(int centerX,int centerY,int sizeX,int sizeY,int R,int G,int B,SDL_Plotter& screen);

//void drawCircle(SDL_Plotter& screen);


#endif /* Objects_h */
