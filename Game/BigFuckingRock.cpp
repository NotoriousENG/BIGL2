
#include "BigFuckingRock.hpp"
#include "TextureManager.hpp"

/* BigFucking Rock is an AI component that will later track the Player's movements to prevent them 
 *from staying in the same place for most of the game, with the game logic for other enemies this adds
 *difficulty to the game as it goes on.
 */

//We are creating a BigFuckingRock
BigFuckingRock::BigFuckingRock(const char* texturesheet, int x, int y){
    objTexture = TextureManager::LoadTexture(texturesheet); //texture file for rock
    xpos = x;
    ypos = y;
    
}

//We are updating BigFuckingRock's Parameters
void BigFuckingRock::update(){
    
    ypos=ypos+5;
    
    //BigFuckingRock Has a Rectangle Hitbox
    //Height = 570
    //Width = 570
    srcRect.h = 570;
    srcRect.w = 570;
    srcRect.x = 0;
    srcRect.y = 0;
    
    destRect.x = xpos;
    destRect.y = ypos;
    
    
    destRect.w = srcRect.w;
    destRect.h = srcRect.h;
}

//We can get the x coordinate of BigFuckingRock
int BigFuckingRock::xval(){
    return xpos;
}

//We can get the y coordinate of BigFuckingRock
int BigFuckingRock::yval(){
    return ypos;
}

//Rendering BigFuckingRock with SDL
void BigFuckingRock::render(){
    SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);
}
