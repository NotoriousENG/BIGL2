#include "PlayerObject.hpp"
#include "TextureManager.hpp"

//Initializes the player object
PlayerObject::PlayerObject(const char* texturesheet, int x, int y){
    
    //makes an object texture
    objTexture = TextureManager::LoadTexture(texturesheet);
    
    //sets x- and y-coordinates
    xpos = x;
    ypos = y;
}


//Updates the player object
void PlayerObject::update(){
    
    //Player dimensions:
    srcRect.h = 570;        //height
    
    srcRect.w = 570;        //width
    
    srcRect.x = 0;          //x position
    
    srcRect.y = 0;          //y position
    
    
    //Mapping player to map coordinates:
    destRect.x = xpos;          //x position
    
    destRect.y = ypos;          //y position
    
    destRect.w = srcRect.w/6;   //width
    
    destRect.h = srcRect.h/6;   //height
}


//Renders the player object
void PlayerObject::render(){
    SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);
}


//Returns x-position
int PlayerObject::xval(){
    return xpos;
}


//Moves the player object to the left
void PlayerObject::moveLeft()
{
    //player cannot move past left boundary of window
    if(xpos<=-20){
        xpos = -20;
    }
    else{
        xpos -= 5;
    }
}


//Moves the player object to the right
void PlayerObject::moveRight()
{
    //player cannot move past right boundary of window
    if(xpos>=730){
        xpos = 730;
    }
    else{
        xpos += 5;
    }
}
