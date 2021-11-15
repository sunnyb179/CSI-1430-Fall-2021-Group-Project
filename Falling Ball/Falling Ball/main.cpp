// Authors: Zhongbo Sun,
// Assignment Title: Group project
// Assignment Description: Game: Falling ball
// Due Date: 12/8/2020
// Date Created: 11/10/2020
// Date Last Modified: 11/10/2020


#include "Game.h"
 
int main(){
    
    game Game;
    Game.init();
    Game.play();
    while(!Game.over())
    {
        Game.update();
    }
    return 0;
    
}
