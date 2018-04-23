
#ifndef AsteroidObject_hpp
#define AsteroidObject_hpp

#include "Game.hpp"

class AsteroidObject{
public:
    
    //asteroid object parameters
    AsteroidObject(const char* texturesheet, int x, int y);
    //asteroid object deconstructor
    ~AsteroidObject();
    
    void update();
    void render();
    int xval();
    int yval();
    
    
    
private:
    int xpos;
    int ypos;
    
    
    //points SDL Texture to an object
    SDL_Texture* objTexture;
    
    //declares the SDL Rectangle
    SDL_Rect srcRect, destRect;
    
};

#endif /* AsteroidObject_hpp */
