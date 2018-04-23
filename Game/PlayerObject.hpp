#include "Game.hpp"

class PlayerObject{
public:
    PlayerObject(const char* texturesheet, int x, int y);
    ~PlayerObject();
    
    void update();
    void render();
    
    void moveLeft();
    void moveRight();
    
    int xval();
    
private:
    int xpos;
    int ypos;
    
     //points SDL Texture to an object
    SDL_Texture* objTexture;
    
    //declares the SDL Rectangle
    SDL_Rect srcRect, destRect;
    
};
