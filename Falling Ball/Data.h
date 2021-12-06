//
//  Data.h
//  Falling Ball
//
//  Created by Zhongbo Sun on 11/10/21.
//

#ifndef Data_h
#define Data_h

#include<iostream>

//General Data
const int WINDOW_Y_SIZE=600;
const int WINDOW_X_SIZE=350;
const int FPS=35;
const double PI=3.1415926;

//Starting Screen Data
const int sBACKGROUND_COLOR_R=219;
const int sBACKGROUND_COLOR_G=166;
const int sBACKGROUND_COLOR_B=208;

const int sGAME_BUTTON_COLOR_R=245;
const int sGAME_BUTTON_COLOR_G=155;
const int sGAME_BUTTON_COLOR_B=108;
const int sGAME_BUTTON_CENTER_X=175;
const int sGAME_BUTTON_CENTER_Y=450;
const int sGAME_BUTTON_SIZE_X=100;
const int sGAME_BUTTON_SIZE_Y=40;

//Game
const int gBACKGROUND_COLOR_R=99;
const int gBACKGROUND_COLOR_G=206;
const int gBACKGROUND_COLOR_B=247;

const int gOBJECT_ROW=5;
const int gOBJECT_COLUMN=7;
const int gOBJECT_ROW_SAPERATION=70;
const int gOBJECT_SHIFT=14;
const int gOBJECT_GENERATE_INITIAL_POSSIBILITY=50; //out of 100 percent
const int gBAll_ADDER_INITIAL_POSSIBILITY=30; //out of 100 percent

const int gSTART_Height=50;
const int gSTART_SPEED=5;//pixel/second
const double gGRAVITY_ACELERATION=0.05;//pixel/second^2
const int gBALL_SHOOT_GAP=10;

const int gSMALL_BAll_R=255;
const int gSMALL_BAll_G=255;
const int gSMALL_BAll_B=255;
const int gSMALL_BALL_RADIUS=10;

const int gOBJECT_R=169;
const int gOBJECT_G=250;
const int gOBJECT_B=110;
const int gSQUAR_SIDE=20;
const int gTRIANGLE_HIEHGT=40;
const int gOBJECT_BALL_RADIUS=20;

const int gBAll_ADDER_R=255;
const int gBAll_ADDER_G=255;
const int gBAll_ADDER_B=255;
const int gBAll_ADDER_RADIUS=10;
const int gBAll_ADDER_HITBOXRAD=11;


#endif /* Data_h */
