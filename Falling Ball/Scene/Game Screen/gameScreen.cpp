//
//  gameScreen.cpp
//  Falling Ball
//
//  Created by Zhongbo Sun on 11/28/21.
//

#include "gameScreen.h"

int gameScreen(SDL_Plotter& screen){
    //Data Abstraction
    int nextScreen=0;
    bool notSelect=true;
    bool fallingBallFalling,gameOver=false;
    
    //Window drawing
    drawBackground(WINDOW_X_SIZE,WINDOW_Y_SIZE,gBACKGROUND_COLOR_R,gBACKGROUND_COLOR_G+100,gBACKGROUND_COLOR_B,screen);
    screen.update();
    
    
    PositionStatus gameObejct[gOBJECT_COLUMN][gOBJECT_ROW];
    int fallingBallAmount=1; //If making the game save and load, do it here
    int mouseX=0,mouseY=0;
    int Objectshift=20;
    
    
    
    
    while(!gameOver){
        notSelect=true;
        
        while(notSelect)
        {
            if(screen.getQuit())
            {
                notSelect=false;
                gameOver=true;
            }
            else if(screen.kbhit())
            {
                screen.getKey();
            }
            else if(screen.getMouseClick(mouseX,mouseY)) //Chang me:: Now is click generate new line
            {
                notSelect=false;
                
                
                for(int i=0;i<gOBJECT_ROW;i++) //find game over or not
                {
                    for(int i=0;i<gOBJECT_ROW;i++)
                    {
                        if(gameObejct[6][i].objectType!=-1)
                        {
                            cout<<"GAME OVER";
                            gameOver=true;
                        }
                    }
                }
                    
                    
                    if(!gameOver)
                    {
                        for(int i=gOBJECT_COLUMN-1;i>0;i--)
                        {
                            for(int ii=0;ii<gOBJECT_ROW;ii++)
                            {
                                gameObejct[i][ii]=gameObejct[i-1][ii];
                                gameObejct[i][ii].centerY-=70; //change this later
                            }
                        }
            
                        
                        for(int i=0;i<gOBJECT_ROW;i++) //initilize first row
                        {
                            if(true){ //Change later, the possibilty of generate a block
                                PositionStatus newObeject;
                                gameObejct[0][i]=newObeject;
                                newObeject.objectType=rand()%3; //Change later, Ramdomlize the type
                                newObeject.objectLife=5; //Change later, Ramdomlize the life
                                newObeject.centerX=(WINDOW_X_SIZE/(gOBJECT_ROW+1))*(i+1)+Objectshift;
                                newObeject.centerY=WINDOW_Y_SIZE-(WINDOW_Y_SIZE-100)/gOBJECT_COLUMN;
                                gameObejct[0][i]=newObeject;
                            }
                        }
                        Objectshift*=-1;
                        
                        drawBackground(WINDOW_X_SIZE,WINDOW_Y_SIZE,gBACKGROUND_COLOR_R,gBACKGROUND_COLOR_G+100,gBACKGROUND_COLOR_B,screen);
                        printObjects(gameObejct,screen);
                    }
                }
            }
        }
    
    
    

    

    
    
    
    
    
    return nextScreen;
}

    
void printObjects(PositionStatus gameObejct[gOBJECT_COLUMN][gOBJECT_ROW],SDL_Plotter& screen){
    for(int i=0;i<gOBJECT_COLUMN;i++)
    {
        for(int ii=0;ii<gOBJECT_ROW;ii++)
        {
            gameObejct[i][ii].drawObject(screen);
            cout<<gameObejct[i][ii].objectType;
        }
        cout<<endl;
    }
    screen.update();
}
