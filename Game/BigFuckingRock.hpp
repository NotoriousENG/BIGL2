
#ifndef BigFuckingRock_hpp
#define BigFuckingRock_hpp
#include "Game.hpp"

#include <stdio.h> // include standard input output header

/* Here we are creating The BigFuckingRock Class
 * BigFuckingRock is an AI component that will track player actions
 * it is designed to make the game more difficult 
 * it will track the player's location which will prevent the player 
 * from staying in the same space
 */

class BigFuckingRock{
    
    //Public: Methods go here
public:
    BigFuckingRock(const char* texturesheet, int x, int y);
    ~BigFuckingRock();
    
    void update();
    void render();
    int xval();
    int yval();
    
    
    //Private: To be initialized goes here
private:
    int xpos;
    int ypos;
    
    SDL_Texture* objTexture;
    SDL_Rect srcRect, destRect;
    
};

#endif /* BigFuckingRock_hpp */
