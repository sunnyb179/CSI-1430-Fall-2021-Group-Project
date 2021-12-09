/*
* Author: Zhongbo Sun
          Leyang Zhou
          Shaoyu Chen
          Yian Ge
          Jake Caraway
* Assignment Title: Falling Ball
* File Name: Objects.h
* Assignment Description: This header file initializes
* Due Date: 12/08/21
* Date Created: 11/10/21
* Date Last Modified: 12/08/21 - 8:13pm
*/

#ifndef Objects_h
#define Objects_h

#include "SDL_Plotter.h"
#include <fstream>
#include <cmath>
#include <vector>
#include "Data.h"


/*
  * Description:
    
  * Return:
    
  * Precondition:
    
  * Postcondition:
    
  *
*/
void drawBackground(int sizeX,int sizeY,int R,int G,int B,SDL_Plotter& screen);


/*
  * Description:
    
  * Return:
    
  * Precondition:
    
  * Postcondition:
    
  *
*/
void drawButton(int centerX,int centerY,int sizeX,int sizeY,int R,int G,int B,SDL_Plotter& screen);


/*
  * Description:
    
  * Return:
    
  * Precondition:
    
  * Postcondition:
    
  *
*/
void drawBallAdder(int centerX,int centerY,SDL_Plotter& screen);


/*
  * Description:
    
  * Return:
    
  * Precondition:
    
  * Postcondition:
    
  *
*/
void drawCircle(int centerX,int centerY,int radius,int R,int G,int B,SDL_Plotter& screen);


/*
  * Description:
    
  * Return:
    
  * Precondition:
    
  * Postcondition:
    
  *
*/
void drawRectangle(int centerX,int centerY,int sizeX,int sizeY,int R,int G,int B,SDL_Plotter& screen);


/*
  * Description:
    
  * Return:
    
  * Precondition:
    
  * Postcondition:
    
  *
*/
void drawTriangle(int centerX,int centerY,int height,int R, int G, int B, SDL_Plotter& screen);


/*
  * Description:
    
  * Return:
    
  * Precondition:
    
  * Postcondition:
    
  *
*/
void plotPoint(int X,int Y,int R,int G,int B,SDL_Plotter& screen);


/*
  * Description:
    
  * Return:
    
  * Precondition:
    
  * Postcondition:
    
  *
*/
void plotChar(int X,int Y,char goal,int fontSize,int R,int G,int B,SDL_Plotter& screen);


/*
  * Description:
    
  * Return:
    
  * Precondition:
    
  * Postcondition:
    
  *
*/
void plotString(const char text[],int numberOfChar,int fontSize,int X,int Y,int R,int G,int B,SDL_Plotter& screen);


/*
  * Description:
    
  * Return:
    
  * Precondition:
    
  * Postcondition:
    
  *
*/
void plotInt(int num,int fontSize,int X,int Y,int R,int G,int B,SDL_Plotter& screen);

#endif /* Objects_h */
