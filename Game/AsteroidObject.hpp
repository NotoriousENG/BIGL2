
#ifndef AsteroidObject_hpp
#define AsteroidObject_hpp

#include "Game.hpp"

class AsteroidObject{
public:
    AsteroidObject(const char* texturesheet, int x, int y);
    ~AsteroidObject();
    
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

#endif /* AsteroidObject_hpp */
