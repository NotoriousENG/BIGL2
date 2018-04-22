#include "Game.hpp"
#include "AsteroidObject.hpp"

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
    
    //Catches if user input is too large
    if (lives>99){
        std::cout<<"Max 99 lives. Lives is now equal to 99."<<std::endl;
        lives=99;
    }
    //Catches negative user input
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
    
    // game window logic
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
            std::cout<<"You died, better luck next time!"<<std::endl;
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
    
    // we print each score
        for(int i = 0; i< initLives; i++){
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
