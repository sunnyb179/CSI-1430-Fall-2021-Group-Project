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
    bool userIsIdol=true;
    bool fallingBallFalling,gameOver=false;
    
    //Window drawing
    drawBackground(WINDOW_X_SIZE,WINDOW_Y_SIZE,gBACKGROUND_COLOR_R,gBACKGROUND_COLOR_G,gBACKGROUND_COLOR_B,screen);
    screen.update();
    
    
    PositionStatus gameObejct[gOBJECT_COLUMN][gOBJECT_ROW];
    int fallingBallAmount=1; //If making the game save and load, do it here
    int mouseX=0,mouseY=0;
    int Objectshift=gOBJECT_SHIFT;
    
    while(!gameOver){
        userIsIdol=true;
        
        while(userIsIdol)
        {
            if(screen.getQuit())
            {
                userIsIdol=false;
                gameOver=true;
            }
            else if(screen.kbhit())
            {
                screen.getKey();
            }
            else if(screen.getMouseClick(mouseX,mouseY)) //Chang me:: Now is click generate new line
            {
                userIsIdol=false;
                
                
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
                        //moving all object to the next line
                        for(int i=gOBJECT_COLUMN-1;i>0;i--)
                        {
                            for(int ii=0;ii<gOBJECT_ROW;ii++)
                            {
                                gameObejct[i][ii]=gameObejct[i-1][ii];
                                gameObejct[i][ii].centerY-=70; //change this later,distance between each line
                            }
                        }
            
                        //add a new roll
                        for(int i=0;i<gOBJECT_ROW;i++)
                        {
                            gameObejct[0][i]=getRandomlizedObject(i,Objectshift,gOBJECT_GENERATE_INITIAL_POSSIBILITY);
                        }
                        Objectshift*=-1;
                        
                        //refresh screen
                        printObjects(gameObejct,screen);
                    }
                }
            }
        }
    return nextScreen;
}



PositionStatus getRandomlizedObject(int i,int Objectshift,int possiblity){
    PositionStatus newObeject;
    if((rand()%100)+1<=possiblity)
    {
        newObeject.objectType=rand()%3; //Change later, Ramdomlize the type
        newObeject.objectLife=5; //Change later, Ramdomlize the life
        newObeject.centerX=(WINDOW_X_SIZE/(gOBJECT_ROW+1))*(i+1)+Objectshift;
        newObeject.centerY=WINDOW_Y_SIZE-(WINDOW_Y_SIZE-100)/gOBJECT_COLUMN;
    }
    return newObeject;
}

    
void printObjects(PositionStatus gameObejct[gOBJECT_COLUMN][gOBJECT_ROW],SDL_Plotter& screen){
    drawBackground(WINDOW_X_SIZE,WINDOW_Y_SIZE,gBACKGROUND_COLOR_R,gBACKGROUND_COLOR_G,gBACKGROUND_COLOR_B,screen);
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

