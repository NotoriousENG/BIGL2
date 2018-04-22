
#ifndef Game_hpp
#define Game_hpp
#include <iostream>
#include "SDL2/SDL.h"
#include "SDL2_image/SDL_image.h"



class Game{
    
public:
    Game();
    ~Game();
    
    //int asters[1000];
    
    void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
    void handleEvents();
    void update();
    void render();
    void clean();
    static SDL_Renderer *renderer;
    
    bool running(){return isRunning;}
    
    bool checkCollision();
    bool checkBigCollision();
    
    //void createBigrock();
    
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
