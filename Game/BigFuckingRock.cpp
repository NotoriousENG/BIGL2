
#include "BigFuckingRock.hpp"
#include "TextureManager.hpp"



BigFuckingRock::BigFuckingRock(const char* texturesheet, int x, int y){
    objTexture = TextureManager::LoadTexture(texturesheet);
    xpos = x;
    ypos = y;
    
}

void BigFuckingRock::update(){
    
    ypos=ypos+3;
    
    srcRect.h = 570;
    srcRect.w = 570;
    srcRect.x = 0;
    srcRect.y = 0;
    
    destRect.x = xpos;
    destRect.y = ypos;
    
    
    destRect.w = srcRect.w;
    destRect.h = srcRect.h;
}

int BigFuckingRock::xval(){
    return xpos;
}
int BigFuckingRock::yval(){
    return ypos;
}

void BigFuckingRock::render(){
    SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);
}
