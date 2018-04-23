#include "Game.hpp"
#include "AsteroidObject.hpp"

/*******************************************************************************************************************************************
 *                                                      DODGER CLONE:                                                                      *
 *                          A C++ Game made using SDL libraries in the style of the classic game Dodger                                    *
 *******************************************************************************************************************************************
 *                                                           By:                                                                           *
 *                                                      Oliver Hodge                                                                       *
 *                                                    Pilar Albar Diaz                                                                     *
 *                                                     Zach Weisblatt                                                                      *
 *                                                      Jack Brennan                                                                       *
 *                                                    Michael O'Connell                                                                    *
 *******************************************************************************************************************************************
 *                                                     Libraries used:                                                                     *
 *                                        SDL: https://www.libsdl.org/download-2.0.php                                                     *
 *                                        SDL_image: https://www.libsdl.org/projects/SDL_image/                                            *
 *                                        SDL_Texture: https://wiki.libsdl.org/SDL_Texture                                                 *
 *******************************************************************************************************************************************
 *                                                      Sources used:                                                                      *
 *                                    LazyFoo (SDL Tutorial): http://lazyfoo.net/tutorials/SDL/index.php                                   *
 *                      Let's Make A Game: https://www.youtube.com/watch?v=QQzAHcojEKg&list=PLhfAbcv9cehhkG7ZQK0nfIGJC_C-wSLrx             *
 *                                              learncpp: http://www.learncpp.com/                                                         *
 *******************************************************************************************************************************************
 *                                                      How to Play:                                                                       *
 *                                       Set the number of times you want to play                                                          *
 *                             Control your rocket using the arrow keys (->) and (<-) or 'a' and 'd'                                       *
 *                                      Avoid Falling Asteroids (Look out for surprises too!)                                              *
 *******************************************************************************************************************************************/

Game *game = nullptr;

int main(int argc, const char * argv[]) {
    
    int lives = 0;
    std::cout<<"How many games do you want to play?"<<std::endl;
    std::cin>>lives;
    while(std::cin.fail()) {
        std::cout << "Error. Try again. Please enter int value 1-99" << std::endl;
        std::cin.clear();
        std::cin.ignore(256,'\n');
        std::cin >> lives;
    } //floors decimals
    if (lives>99){
        std::cout<<"Max 99 lives. Lives is now equal to 99."<<std::endl;
        lives=99;
    }
    if(lives<1){
        std::cout<<"Min 1 life. Lives is now equal to 1."<<std::endl;
        lives=1;
    }
    
    
    
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
        bool bigalive = false;
        game->handleEvents();
        game->update();
        game->render();
        alive = game->checkCollision();
        bigalive = game->checkBigCollision();
        
        
        
        
        frameTime = SDL_GetTicks() - frameStart;
        
        if (frameDelay > frameTime){
            SDL_Delay(frameDelay - frameTime);
        }
        
        if ((alive == true)||(bigalive == true)){
            lives--;
            std::cout<<"You died."<<std::endl;
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
