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
    
    //Error handling for wrong variable type input
    //Also handles too large/small inputs i.e. 2^31
    
    
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
    
    
    
    //Creation of a score array to store the score of a game
    int *scores = new int[lives];
    
     // lives is the ammount of times the game is to be played
    int i = lives;
    
    // we need to save the initial number of lives for later use
    int initLives = lives;
    
    
    
     //while there are still more lives (plays) left
    while(lives!=0){
    
        
    //fps - frames per second
    const int fps = 60;
   
    const int frameDelay = 1000/fps;
    
    Uint32 frameStart;
    int frameTime;
    
    game = new Game();
    
    //game window logic
    game->init("BirchEngine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, false);
    
    
    
    
    
    
    while (game->running()){
        
        
        //how long the game is going
        // 1 tick = 1 millisecond
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
        
        
        //When you die, the ammount of times you can play is decrimented
        if ((alive == true)||(bigalive == true)){
            lives--;
            std::cout<<"You died, better luck next time! :) "<<std::endl;
            break;
        }
        
        
        
    }
        
        // when you die the score is recorded in an array and printed
        // and the game restarts
        scores[initLives-i] = SDL_GetTicks()/1000;
        std::cout<< scores[initLives-i]<<std::endl;
        i--;
        game->clean();
    }
    
    // temporary High Score variable
    int temp = 0;
    
    for(int i = 0; i< initLives; i++){
         // we print each score
        std::cout<<scores[i]<<std::endl;
    }
    
    
    // we will find the highest score
    // we will look through the entire array of scores
    
    for(int k = 0; k< initLives; k++){
            // if the score is greater than temp
            if(scores[k] > temp){
            // we overwrite temp with the higher score
                temp = scores[k];
            }
        
    }
    
    // game loop is over
    
    // We print the high score
    std::cout << "High score: " << temp << std::endl;
    
    
    
    // We exit the program
    return 0;
}
