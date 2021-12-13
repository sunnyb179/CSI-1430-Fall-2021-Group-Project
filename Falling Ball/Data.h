/*
* Author: Zhongbo Sun
          Leyang Zhou
          Shaoyu Chen
          Yian Ge
          Jake Caraway
* Assignment Title: Falling Ball
* File Name: Data.h
* Assignment Description: This file contains and organizes the required
  constants for the
* Due Date: 12/08/21
* Date Created: 11/10/21
* Date Last Modified: 12/08/21 - 8:18pm
*/

#ifndef Data_h
#define Data_h

#include<iostream>

//General Data
const int WINDOW_Y_SIZE=600;
const int WINDOW_X_SIZE=350;
const int FPS=60;
const double PI=3.1415926;

//Starting Screen Data
const int sBACKGROUND_COLOR_R=219;
const int sBACKGROUND_COLOR_G=166;
const int sBACKGROUND_COLOR_B=208;

//
const char sSTART[10]="start";
const int sSTART_LENGTH=5;
const int sSTART_X=100;
const int sSTART_Y=440;
const int sSTART_SIZE=6;
const int sSTART_R=255;
const int sSTART_G=255;
const int sSTART_B=255;

//
const char sTITLE_Line1[10]="falling";
const int sTITLE_Line1_Length=7;
const char sTITLE_Line2[10]="ball";
const int sTITLE_LINE2_LENGTH=4;
const int sTITLE_LINE1_X=20;
const int sTITLE_Line1_Y=100;
const int sTITLE_Line2_X=200;
const int sTITLE_Line2_Y=150;
const int sTITLE_SIZE=6;
const int sTITLE_COLOR_R=255;
const int sTITLE_COLOR_G=255;
const int sTITLE_COLOR_B=255;

//
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
const int gBACKGROUND_COLOR_B=240;

//
const int gOBJECT_ROW=5;
const int gOBJECT_COLUMN=7;
const int gOBJECT_ROW_SAPERATION=70;
const int gOBJECT_SHIFT=14;
const int gOBJECT_GENERATE_INITIAL_POSSIBILITY=50; //out of 100 percent
const int gBAll_ADDER_INITIAL_POSSIBILITY=20; //out of 100 percent

//
const int gSTART_Height=50;
const int gSTART_SPEED=6;//pixel/second
const double gGRAVITY_ACELERATION=0.2;//pixel/second^2
const double gBounce_ACELERATION_PERCENTAGE=0.7;
const int gBALL_SHOOT_GAP=10;

//
const int gSMALL_BAll_R=255;
const int gSMALL_BAll_G=255;
const int gSMALL_BAll_B=255;
const int gSMALL_BALL_RADIUS=10;

//
const int gOBJECT_R=170;
const int gOBJECT_G=250;
const int gOBJECT_B=100;
const int gSQUAR_SIDE=20;
const int gTRIANGLE_HIEHGT=40;
const int gOBJECT_BALL_RADIUS=20;
const int gOBJECT_LIFE_FONT_SIZE=4;

//
const int gBAll_ADDER_R=255;
const int gBAll_ADDER_G=255;
const int gBAll_ADDER_B=255;
const int gBAll_ADDER_RADIUS=10;
const int gBAll_ADDER_HITBOXRAD=11;

//
const char gSCORE_LINE[10]="score";
const int gSCORE_LINE_LENGTH=5;
const int gSCORE_LINE_X=20;
const int gSCORE_LINE_Y=10;
const int gSCORE_LINE_SIZE=5;
const int gSCORE_LINE_COLOR_R=255;
const int gSCORE_LINE_COLOR_G=255;
const int gSCORE_LINE_COLOR_B=255;

//
const char gFPS[10]="fps";
const int gFPS_LENGTH=3;
const int gFPS_X=250;
const int gFPS_Y=10;
const int gFPS_SIZE=3;
const int gFPS_R=255;
const int gFPS_G=255;
const int gFPS_B=255;

//
const char gSTOP[10]="gameover";
const int gSTOP_LENGTH=8;
const int gSTOP_X=40;
const int gSTOP_Y=275;
const int gSTOP_SIZE=7;
const int gSTOP_R=255;
const int gSTOP_G=0;
const int gSTOP_B=0;


#endif /* Data_h */
