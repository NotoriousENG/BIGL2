#include "Game.hpp"
#include "AsteroidObject.hpp"

Game *game = nullptr;

int main(int argc, const char * argv[]) {
    
    int lives = 0;
    std::cout<<"Enter desired # of lives: (enter int value)"<<std::endl;
    std::cin>>lives;
    
    
    
    
    //added score
    int *scores = new int[lives];
    int i = lives;
    int initLives = lives;
    
    
    
    
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
        //game->createBigrock();
        
        
        
        frameTime = SDL_GetTicks() - frameStart;
        
        if (frameDelay > frameTime){
            SDL_Delay(frameDelay - frameTime);
        }
        
        if (alive == true){
            lives--;
            break;
        }
        
        
        
    }
        scores[initLives-i] = SDL_GetTicks()/1000;
        std::cout<< scores[initLives-i]<<std::endl;
        i--;
        game->clean();
    }
    
    int temp = 0;
    
        for(int i = 0; i< initLives; i++){
        
                std::cout<<scores[i]<<std::endl;
        
            }
    
        for(int k = 0; k< initLives; k++){
        
                
        
                if(scores[k] > temp){
            
                        temp = scores[k];
            
                    }
        
            }
    
        std::cout << "High score: " << temp << std::endl;
    
    
    
    
    return 0;
}
