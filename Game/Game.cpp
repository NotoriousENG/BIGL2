
#include "Game.hpp"
#include "TextureManager.hpp"
#include "GameObject.hpp"
#include "PlayerObject.hpp"
#include "Map.hpp"

#include "Components.hpp"
#include "AsteroidObject.hpp"
#include <vector>
#include "BigFuckingRock.hpp"
//#include "ECS.hpp"

PlayerObject* player;




/*AsteroidObject* enemy;
AsteroidObject* enemy2;
AsteroidObject* enemy3;
AsteroidObject* enemy4;
AsteroidObject* enemy5;
*/



AsteroidObject *aster[1000];

BigFuckingRock *rockstar[20];

Map* map;

SDL_Renderer* Game::renderer = nullptr;
Manager manager;
auto& newPlayer(manager.addEntity());


Game::Game(){
    
}
Game::~Game(){
    
}

int bigrock = 0;

int asteroidspastzero=0;





void Game::init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen){
    
    
    
    int flags=0;
    if (fullscreen){
        flags=SDL_WINDOW_FULLSCREEN;
    }
    
    if(SDL_Init(SDL_INIT_EVERYTHING)==0){
        std::cout<<"Subsystems Initialized..."<< std::endl;
        
        window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        if(window){
            std::cout<<"Window created..."<<std::endl;
        }
        renderer=SDL_CreateRenderer(window, -1, 0);
        if(renderer){
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            std::cout<<"Renderer Created..."<<std::endl;
        }
        
        isRunning=true;
    }
    
    else{
        isRunning=false;
    }
    
    player = new PlayerObject("/Users/oliverhodge/Desktop/Game/Assets/rocket1.png",400,550);
    
    /*
    enemy = new AsteroidObject("/Users/oliverhodge/Desktop/Game/Assets/rock.png",100,0);
    enemy2 = new AsteroidObject("/Users/oliverhodge/Desktop/Game/Assets/rock.png",200,-10);
    enemy3 = new AsteroidObject("/Users/oliverhodge/Desktop/Game/Assets/rock.png",300,-60);
    enemy4 = new AsteroidObject("/Users/oliverhodge/Desktop/Game/Assets/rock.png",400,-100);
    enemy5 = new AsteroidObject("/Users/oliverhodge/Desktop/Game/Assets/rock.png",500,-150);
    */
    
    
    int h = 0;
    for (int t = 0; t<1000; t++){
        aster[t] = new AsteroidObject("/Users/oliverhodge/Desktop/Game/Assets/rock.png", rand() % 800, h);
        h=h-50;
    }
    
    
     
    
    
    
    
    
    
    
    map = new Map();
    
    //newPlayer.addComponent<PositionComponent>();
    
}

void Game::handleEvents(){
    
    
    
    
    
    
    SDL_Event event;
    SDL_PollEvent(&event);
    switch(event.type){
        case SDL_QUIT:
            isRunning=false;
            break;
            
        default:
            break;
    }
    
    const Uint8* currentKeyState = SDL_GetKeyboardState(NULL);
    if (currentKeyState[SDL_SCANCODE_A] || currentKeyState[SDL_SCANCODE_LEFT])
    {
        player->moveLeft();
    }
    if (currentKeyState[SDL_SCANCODE_D] || currentKeyState[SDL_SCANCODE_RIGHT])
    {
        player->moveRight();
    }
}



void Game::update(){
    
    
    ticks = SDL_GetTicks();
    std::cout<<ticks<<std::endl;
    
    
    if((ticks > 20000)&&()){
        int location = player->xval();
        rockstar[bigrock] = new BigFuckingRock("/Users/oliverhodge/Desktop/Game/Assets/rock.png", location-200, -200);
        bigrock++;
    }
    
    player->update();
    
    /*enemy->update();
    enemy2->update();
    enemy3->update();
    enemy4->update();
    enemy5->update();
    manager.update();
    */
    
    
    for (int t = 0; t<1000; t++){
        aster[t]->update();
    }
    if(rockstar[bigrock]!=NULL){rockstar[bigrock]->update();}
    
    
}



void Game::render(){
    
    SDL_RenderClear(renderer);
    map->drawMap();
    player->render();
   
    /*
    enemy->render();
    enemy2->render();
    enemy3->render();
    enemy4->render();
    enemy5->render();
    */
    
    for (int t = 0; t<1000; t++){
        aster[t]->render();
    }
    if(rockstar[bigrock]!=NULL){rockstar[bigrock]->render();}
    
    //rockstar[bigrock]->render();
    
    
   
  
    
    
    SDL_RenderPresent(renderer);
    
}

void Game::clean(){
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout<<"Game Cleaned..."<<std::endl;
}



bool Game::checkCollision(){
    int x = player->xval();
    for (int y = 0; y<1000; y++){
        int h = aster[y]->yval();
        int g = aster[y]->xval();
        if((h == 550)&&(((g<=(x+40)&&(g>=x)))||((g<=x)&&(g>=(x-40))))){
            std::cout<<"fuck you loser"<<std::endl;
            collision = true;
        }
        
    }
    
    
    
    
    
    return collision;
}


