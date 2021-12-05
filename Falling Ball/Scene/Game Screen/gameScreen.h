//
//  gameScreen.h
//  Falling Ball
//
//  Created by Zhongbo Sun on 11/28/21.
//

#ifndef gameScreen_h
#define gameScreen_h

#include "Objects.h"
#include "gameObjectStatus.h"
#include "Data.h"

int gameScreen(SDL_Plotter& screen);

PositionStatus getRandomlizedObject(int i,int Objectshift,int possiblity);

void printObjects(PositionStatus gameObejct[gOBJECT_COLUMN][gOBJECT_ROW],SDL_Plotter& screen);

#endif /* gameScreen_h */
