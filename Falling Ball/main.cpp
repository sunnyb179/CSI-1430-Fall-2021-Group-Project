// Authors: Zhongbo Sun,
// Assignment Title: Group project
// Assignment Description: Game: Falling ball
// Due Date: 12/8/2020
// Date Created: 11/10/2020
// Date Last Modified: 11/10/2020


#include "Game.h"
 
int main(){
    game Game;
    
    SDL_Plotter screen(WINDOW_X_SIZE,WINDOW_Y_SIZE);
    
    Game.init(screen);
    
    Game.play(screen);
    
    while(!Game.over(screen))
    {
        Game.update(screen);
    }
    return 0;
    
}
