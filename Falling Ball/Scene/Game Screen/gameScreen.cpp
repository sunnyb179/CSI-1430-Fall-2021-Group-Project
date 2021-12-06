//
//  gameScreen.cpp
//  Falling Ball
//
//  Created by Zhongbo Sun on 11/28/21.
//

#include "gameScreen.h"

int gameScreen(SDL_Plotter& screen){
    //Data Abstraction
    int nextScreen=0,timeForFrame=round(1.0/FPS*1000),timeForPause=0;
    clock_t frameTime;
    bool gameOver=false;
    
    //Window drawing
    drawBackground(WINDOW_X_SIZE,WINDOW_Y_SIZE,gBACKGROUND_COLOR_R,gBACKGROUND_COLOR_G,gBACKGROUND_COLOR_B,screen);
    screen.update();
    
    //If making the game save and load, do it here//////////////////////////////
    PositionStatus gameObejct[gOBJECT_COLUMN][gOBJECT_ROW]; //storing all obejct
    
    int fallingBallAmount=1;
    //falling ball amount fix me.(up)
    
    int currentRowAmount=0;
    
    int currentGameScore=0;
    //If making the game save and load, do it here//////////////////////////////
    
    int mouseX=0,mouseY=0; //mouse position
    
    int Objectshift=gOBJECT_SHIFT;
    
    
    while(!gameOver){
        //moving all object to the next line
        for(int i=gOBJECT_COLUMN-1;i>0;i--)
        {
            for(int ii=0;ii<gOBJECT_ROW;ii++)
            {
                swap(gameObejct[i][ii],gameObejct[i-1][ii]);
                gameObejct[i][ii].centerY-=gOBJECT_ROW_SAPERATION;
            }
        }

        //Add a new row
        currentRowAmount++;
        for(int i=0;i<gOBJECT_ROW;i++)
        {
            gameObejct[0][i]=getRandomlizedObject(i,Objectshift,currentRowAmount);
        }
        Objectshift*=-1;
        
        //
        //FOR BALL FALLING START HERE
        //
        
        vector<fallingBall> allBallOnScreen; //All balls that shoot is in here.
        //Load the ball in
        for(int i=0;i<fallingBallAmount;i++)
        {
            allBallOnScreen.push_back(newBall());
        }
        
        //Paint the screen
        printObjects(gameObejct,screen);
        allBallOnScreen[0].drawBall(screen);
        screen.update();
        
        //Wait for user to shoot
        bool userIsIdol=true;
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
            else if(screen.getMouseClick(mouseX,mouseY))
            {
                userIsIdol=false;
            }
        }
        
        //Run all the ball
        if(!gameOver)
        {
            //Find the initial volcity of all ball.
            double findXV,findYV;
            findYV=(mouseY-allBallOnScreen[0].centerY)/sqrt(pow(mouseY-allBallOnScreen[0].centerY,2)+pow(mouseX-allBallOnScreen[0].centerX,2))*gSTART_SPEED;
            findXV=(mouseX-allBallOnScreen[0].centerX)/sqrt(pow(mouseY-allBallOnScreen[0].centerY,2)+pow(mouseX-allBallOnScreen[0].centerX,2))*gSTART_SPEED;
            for(int i=0;i<fallingBallAmount;i++)
            {
                allBallOnScreen[i].volcityX=findXV;
                allBallOnScreen[i].volcityY=findYV;
            }
            
            //Run the ball falling animation
            int frame=0,currentBallAmount=1,ballOut=0;
            while(currentBallAmount!=0)
            {
                frameTime=clock();
                frame++; //Current frame
                
                //Release a new ball
                if(frame%gBALL_SHOOT_GAP==0&&currentBallAmount+ballOut<fallingBallAmount)
                {
                    currentBallAmount++;
                }
                
                //Calculate each ball next frame status
                for(int i=0;i<currentBallAmount;i++)
                {
                    if(allBallOnScreen[i].centerX<gSMALL_BALL_RADIUS||allBallOnScreen[i].centerX>WINDOW_X_SIZE-gSMALL_BALL_RADIUS)
                    {
                        allBallOnScreen[i].volcityX*=-1;
                    }
                    else if(allBallOnScreen[i].centerY<gSMALL_BALL_RADIUS)
                    {
                        allBallOnScreen[i].volcityY*=-1;
                    }
                    
                    //HERE IS TESTING FOR OBJECT COLLOSION//////////////
                    for(int i=0;i<gOBJECT_COLUMN;i++)
                    {
                        for(int ii=0;ii<gOBJECT_ROW;ii++)
                        {
                            double bounceAngle=INFINITY;
                            if(isCollide(allBallOnScreen[i],gameObejct[i][ii],bounceAngle))
                            {
                                
                                
                                
                                
                                gameObejct[i][ii].objectLife--;
                                if(gameObejct[i][ii].objectLife==0)
                                {
                                    gameObejct[i][ii].objectType=-1;
                                }
                                
                                if(bounceAngle==INFINITY)
                                {
                                    fallingBallAmount++;
                                    allBallOnScreen.push_back(newBall());
                                    allBallOnScreen[fallingBallAmount-1].volcityY=findYV;
                                    allBallOnScreen[fallingBallAmount-1].volcityX=findXV;
                                    swap(allBallOnScreen[fallingBallAmount-1],allBallOnScreen[fallingBallAmount-ballOut-1]);
                                }
                                else
                                {
                                    currentGameScore++;
                                    if(bounceAngle==90||bounceAngle==270)
                                    {
                                        allBallOnScreen[i].volcityX*=-1;
                                    }
                                    else
                                    {
                                        allBallOnScreen[i].volcityY*=-1;
                                    }
                                    //HERE
                                }
                                //NEED A LOT OF HARD WORK
                            }
                        }
                    }
                    //HERE IS TESTING FOR OBJECT COLLOSION//////////////
                    
                    //Gravity
                    allBallOnScreen[i].volcityY+=gGRAVITY_ACELERATION;
                    
                    //Position
                    allBallOnScreen[i].centerY+=allBallOnScreen[i].volcityY;
                    allBallOnScreen[i].centerX+=allBallOnScreen[i].volcityX;
                    
                    if(allBallOnScreen[i].centerY-gSMALL_BALL_RADIUS>WINDOW_Y_SIZE)
                    {
                        swap(allBallOnScreen[i],allBallOnScreen[currentBallAmount-1]);
                        swap(allBallOnScreen[currentBallAmount-1],allBallOnScreen[fallingBallAmount-ballOut-1]);
                        currentBallAmount--;
                        ballOut++;
                    }
                }
                
                //Paint the next frame to screen
                printObjects(gameObejct,screen);
                for(int i=0;i<currentBallAmount;i++)
                {
                    allBallOnScreen[i].drawBall(screen);
                }
                
                //Delay for good visual
                frameTime=clock()-frameTime;
                int duration = round((frameTime / (double) CLOCKS_PER_SEC)*1000);
                timeForPause=timeForFrame-duration;
                if(timeForPause<0)
                {
                    cout<<"WARNING CHANGE FPS TO AT MOST"<<round(1/(duration/1000.0))<<endl;
                }
                else
                {
                    screen.Sleep(timeForPause);
                }
                screen.update();
            }
            
            //
            //END OF BALL FALLING
            //
        }
        
        //Test for game Over
        for(int i=0;i<gOBJECT_ROW&&!gameOver;i++) //find game over or not
        {
            if(gameObejct[6][i].objectType!=-1)
            {
                cout<<"GAME OVER";//ADD
                gameOver=true;
            }
        }
    }
    return nextScreen;
}



PositionStatus getRandomlizedObject(int i,int Objectshift,int currentRowAmount){
    PositionStatus newObeject;
    if((rand()%100)+1<=gOBJECT_GENERATE_INITIAL_POSSIBILITY)
    {
        newObeject.objectType=rand()%3;
        newObeject.objectLife=rand()%(currentRowAmount*2)+1; //Change later, Ramdomlize the life
        newObeject.centerX=(WINDOW_X_SIZE/(gOBJECT_ROW+1))*(i+1)+Objectshift;
        newObeject.centerY=WINDOW_Y_SIZE-(WINDOW_Y_SIZE-100)/gOBJECT_COLUMN;
    }
    else if((rand()%100)+1<=gBAll_ADDER_INITIAL_POSSIBILITY)
    {
        newObeject.objectType=3;
        newObeject.objectLife=1;
        newObeject.centerX=(WINDOW_X_SIZE/(gOBJECT_ROW+1))*(i+1)+Objectshift;
        newObeject.centerY=WINDOW_Y_SIZE-(WINDOW_Y_SIZE-100)/gOBJECT_COLUMN;
    }
    return newObeject;
}

fallingBall newBall(){
    fallingBall ball;
    return ball;
}

    
void printObjects(PositionStatus gameObejct[gOBJECT_COLUMN][gOBJECT_ROW],SDL_Plotter& screen){
    drawBackground(WINDOW_X_SIZE,WINDOW_Y_SIZE,gBACKGROUND_COLOR_R,gBACKGROUND_COLOR_G,gBACKGROUND_COLOR_B,screen);
    for(int i=0;i<gOBJECT_COLUMN;i++)
    {
        for(int ii=0;ii<gOBJECT_ROW;ii++)
        {
            gameObejct[i][ii].drawObject(screen);
        }
    }
}

bool isCollide(fallingBall ball,PositionStatus Object,double& bounceAngle){
    bool collide=false;
    if(Object.objectType==0)
    {
        /* is bad
        int Otop,Obottom,Oleft,Oright;
        double Btop,Bbottom,Bleft,Bright;
        Otop=Object.centerY-gSQUAR_SIDE;
        Obottom=Object.centerY+gSQUAR_SIDE;
        Oleft=Object.centerX-gSQUAR_SIDE;
        Oright=Object.centerX+gSQUAR_SIDE;
        Btop=ball.centerY-gSMALL_BALL_RADIUS;
        Bbottom=ball.centerY+gSMALL_BALL_RADIUS;
        Bleft=ball.centerX-gSMALL_BALL_RADIUS;
        Bright=ball.centerX+gSMALL_BALL_RADIUS;
        if(Btop>=Otop&&ball.centerX<Oright&&ball.centerX>Oleft&&ball.centerY<Object.centerY)
        {
            cout<<"TOP ";
            collide=true;
            bounceAngle=0;
        }
        else if(Bleft>=Oleft&&ball.centerY<Obottom&&ball.centerY>Otop&&ball.centerX<Object.centerX)
        {
            cout<<"Left ";
            collide=true;
            bounceAngle=90;
        }
        else if(Bright<=Oright&&ball.centerY<Obottom&&ball.centerY>Otop&&ball.centerX>Object.centerX)
        {
            cout<<"RIGHT ";
            collide=true;
            bounceAngle=270;
        }
        else if(Bbottom<=Obottom&&ball.centerX<Oright&&ball.centerX>Oleft&&ball.centerY>Object.centerY)
        {
            cout<<"DOWN ";
            collide=true;
            bounceAngle=180;
        }
        */
    }
    else if(Object.objectType==1)
    {
        
    }
    else if(Object.objectType==2)
    {
        
    }
    else if(Object.objectType==3)
    {
        double distance=sqrt(pow(round(ball.centerX)-Object.centerX,2)+pow(round(ball.centerY)-Object.centerY,2));
        if(distance<gSMALL_BALL_RADIUS+gBAll_ADDER_HITBOXRAD)
        {
            collide=true;
        }
    }
    return collide;
}

