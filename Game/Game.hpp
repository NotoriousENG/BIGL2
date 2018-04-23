
#ifndef Game_hpp
#define Game_hpp
#include <iostream>
#include "SDL2/SDL.h"
#include "SDL2_image/SDL_image.h"



class Game{
    
public:
    //declares variables as public
    
    //Game method and parameters
    Game();
    //Game
    ~Game();
    
    //initializing method and parameters
    void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
    //handle events method
    void handleEvents();
    //update method
    void update();
    //render method
    void render();
    //clean up method
    void clean();
    //SDL points to renderer
    static SDL_Renderer *renderer;
    
    //running method and return variable
    bool running(){return isRunning;}
    //check collision method
    bool checkCollision();
    //endede here
    bool checkBigCollision();
    std::string getRandomSprite();
    
 
    
private:
    int cnt;
    bool isRunning;
    bool collision = false;
    bool BigCollision = false;
    int asteroidspastzero;
    SDL_Window *window;
    int ticks;
    int val;
    int location;
    
    
    
};

#endif /* Game_hpp */
