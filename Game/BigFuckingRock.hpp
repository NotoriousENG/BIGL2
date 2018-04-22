
#ifndef BigFuckingRock_hpp
#define BigFuckingRock_hpp
#include "Game.hpp"

#include <stdio.h>

class BigFuckingRock{
public:
    BigFuckingRock(const char* texturesheet, int x, int y);
    ~BigFuckingRock();
    
    void update();
    void render();
    int xval();
    int yval();
    
    
    
private:
    int xpos;
    int ypos;
    
    SDL_Texture* objTexture;
    SDL_Rect srcRect, destRect;
    
};

#endif /* BigFuckingRock_hpp */
