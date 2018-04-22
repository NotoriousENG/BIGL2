
#include "AsteroidObject.hpp"


//#include "PlayerObject.hpp"
#include "TextureManager.hpp"

AsteroidObject::AsteroidObject(const char* texturesheet, int x, int y){
    objTexture = TextureManager::LoadTexture(texturesheet);
    xpos = x;
    ypos = y;
}

void AsteroidObject::update(){
    
    ypos=ypos+5;
    
    srcRect.h = 570;
    srcRect.w = 570;
    srcRect.x = 0;
    srcRect.y = 0;
    
    destRect.x = xpos;
    destRect.y = ypos;
    destRect.w = srcRect.w/6;
    destRect.h = srcRect.h/6;
}

int AsteroidObject::xval(){
    return xpos;
}
int AsteroidObject::yval(){
    return ypos;
}

void AsteroidObject::render(){
    SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);
}

