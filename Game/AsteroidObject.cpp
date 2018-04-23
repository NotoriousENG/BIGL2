#include "AsteroidObject.hpp"
#include "TextureManager.hpp"


//Initializes the asteroid object
AsteroidObject::AsteroidObject(const char* texturesheet, int x, int y){
    
    //makes an object texture
    objTexture = TextureManager::LoadTexture(texturesheet);
    
    
    //sets x- and y-coordinates
    xpos = x;
    ypos = y;
}


//Updates the asteroid object
void AsteroidObject::update(){
    
    //each asteroid falls 5 pixels downwards every update loop
    ypos=ypos+5;
    
    //Asteroid dimensions:
    srcRect.h = 570;    //height
    
    srcRect.w = 570;    //width
    
    srcRect.x = 0;      //x position
    
    srcRect.y = 0;      //y position
    
    
    //Mapping asteroid to map coordinates:
    destRect.x = xpos;          //x position
    
    destRect.y = ypos;          //y position
    
    destRect.w = srcRect.w/6;   //height
    
    destRect.h = srcRect.h/6;   //width
}



//Returns x-position
int AsteroidObject::xval(){
    return xpos;
}


//Returns y-position
int AsteroidObject::yval(){
    return ypos;
}


//Renders the asteroid object
void AsteroidObject::render(){
    SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);
}
