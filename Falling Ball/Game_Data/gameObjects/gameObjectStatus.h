

//
//  gameObjectStatus.h
//  Falling Ball
//
//  Created by Zhongbo Sun on 12/4/21.
//

#ifndef gameObjectStatus_h
#define gameObjectStatus_h

#include "Objects.h"
#include "Data.h"

struct PositionStatus{
    int R=gOBJECT_R;
    int G=gOBJECT_G;
    int B=gOBJECT_B;
    int objectType=-1;
    int objectLife=0;
    int centerX=-1;
    int centerY=-1;
    void drawObject(SDL_Plotter& screen);
};



#endif /* gameObjectStatus_h */
