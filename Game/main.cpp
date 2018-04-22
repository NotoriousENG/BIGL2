#include "Game.hpp"
#include "AsteroidObject.hpp"

Game *game = nullptr;

int main(int argc, const char * argv[]) {
    
    int lives = 0;
    std::cout<<"Enter desired # of lives: (enter int value)"<<std::endl;
    std::cin>>lives;
    
    while(lives!=0){
    
    const int fps = 60;
   
    const int frameDelay = 1000/fps;
    
    Uint32 frameStart;
    int frameTime;
    
    game = new Game();
    
    game->init("BirchEngine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, false);
    
    
    
    
    
    
    while (game->running()){
        
        frameStart = SDL_GetTicks();
        
        
        bool alive = false;
        game->handleEvents();
        game->update();
        game->render();
        alive = game->checkCollision();
        
        
        
        frameTime = SDL_GetTicks() - frameStart;
        
        if (frameDelay > frameTime){
            SDL_Delay(frameDelay - frameTime);
        }
        
        if (alive == true){
            lives--;
            break;
        }
        
    }
        game->clean();
    }
    
    
    return 0;
}
