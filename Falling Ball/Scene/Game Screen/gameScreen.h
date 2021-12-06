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
#include "fallingBall.h"
#include "Data.h"
#include <vector>
#include <ctime>

int gameScreen(SDL_Plotter& screen);

PositionStatus getRandomlizedObject(int i,int Objectshift,int currentRowAmount);

fallingBall newBall();

void printObjects(PositionStatus gameObejct[gOBJECT_COLUMN][gOBJECT_ROW],SDL_Plotter& screen);

bool isCollide(fallingBall ball,PositionStatus Object,double& bounceAngle);



#endif /* gameScreen_h */
