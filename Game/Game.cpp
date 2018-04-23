
#include "Game.hpp"
#include "TextureManager.hpp"
#include "GameObject.hpp"
#include "PlayerObject.hpp"
#include "Map.hpp"


#include "AsteroidObject.hpp"
#include <vector>
#include "BigFuckingRock.hpp"


PlayerObject* player;








AsteroidObject *aster[1000];

BigFuckingRock *rockstar[40];

Map* map;

SDL_Renderer* Game::renderer = nullptr;



Game::Game(){
    
}
Game::~Game(){
    
}

int bigrock = 0;

int asteroidspastzero=0;

std::string Game::getRandomSprite(){
    int spriteNum = 1 + rand() % 3;
    
    std::string path;
    switch (spriteNum){
        case 1:
            path = "/Users/oliverhodge/Desktop/Game/Assets/rock2.png";
            break;
        case 2:
            path = "/Users/oliverhodge/Desktop/Game/Assets/rock3.png";
            break;
        case 3:
            path = "/Users/oliverhodge/Desktop/Game/Assets/rock4.png";
            break;
        case 4:
            path = "/Users/oliverhodge/Desktop/Game/Assets/rock5.png";
            break;
        default:
            path = "/Users/oliverhodge/Desktop/Game/Assets/rock.png";
            break;
    }
    return path;
    
}





void Game::init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen){
    
    
    
    int flags=0;
    if (fullscreen){
        flags=SDL_WINDOW_FULLSCREEN;
    }
    
    if(SDL_Init(SDL_INIT_EVERYTHING)==0){
       
        
        window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        
        renderer=SDL_CreateRenderer(window, -1, 0);
        if(renderer){
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            
        }
        
        isRunning=true;
    }
    
    else{
        isRunning=false;
    }
    
    player = new PlayerObject("/Users/oliverhodge/Desktop/Game/Assets/rocket1.png",400,550);
    
    
    

    
    
    
    
    
    int h = 0;
    for (int t = 0; t<50; t++){
        
        aster[t] = new AsteroidObject("/Users/oliverhodge/Desktop/Game/Assets/rock2.png", rand() % 800, h);
        h=h-200;
    }
    
    
    for (int t = 50; t<100; t++){
        aster[t] = new AsteroidObject("/Users/oliverhodge/Desktop/Game/Assets/rock3.png", rand() % 800, h);
        h=h-130;
    }
    
    
    for (int t = 100; t<150; t++){
        aster[t] = new AsteroidObject("/Users/oliverhodge/Desktop/Game/Assets/rock4.png", rand() % 800, h);
        h=h-100;
    }
    
    
    for (int t = 150; t<200; t++){
        aster[t] = new AsteroidObject("/Users/oliverhodge/Desktop/Game/Assets/rock5.png", rand() % 800, h);
        h=h-90;
    }
    
    
    for (int t = 200; t<250; t++){
        aster[t] = new AsteroidObject("/Users/oliverhodge/Desktop/Game/Assets/rock.png", rand() % 800, h);
        h=h-80;
    }
    
   
    for (int t = 250; t<300; t++){
        aster[t] = new AsteroidObject("/Users/oliverhodge/Desktop/Game/Assets/rock2.png", rand() % 800, h);
        h=h-70;
    }
    
    
    for (int t = 300; t<350; t++){
        aster[t] = new AsteroidObject("/Users/oliverhodge/Desktop/Game/Assets/rock3.png", rand() % 800, h);
        h=h-60;
    }
    
    
    for (int t = 350; t<400; t++){
        aster[t] = new AsteroidObject("/Users/oliverhodge/Desktop/Game/Assets/rock4.png", rand() % 800, h);
        h=h-50;
    }
    
    
    for (int t = 400; t<450; t++){
        aster[t] = new AsteroidObject("/Users/oliverhodge/Desktop/Game/Assets/rock5.png", rand() % 800, h);
        h=h-40;
    }
    
   
    for (int t = 450; t<500; t++){
        aster[t] = new AsteroidObject("/Users/oliverhodge/Desktop/Game/Assets/rock.png", rand() % 800, h);
        h=h-30;
    }
    
    
    for (int t = 500; t<550; t++){
        aster[t] = new AsteroidObject("/Users/oliverhodge/Desktop/Game/Assets/rock2.png", rand() % 800, h);
        h=h-27;
    }
    
   
    for (int t = 550; t<600; t++){
        aster[t] = new AsteroidObject("/Users/oliverhodge/Desktop/Game/Assets/rock3.png", rand() % 800, h);
        h=h-25;
    }
    
    
    for (int t = 600; t<650; t++){
        aster[t] = new AsteroidObject("/Users/oliverhodge/Desktop/Game/Assets/rock4.png", rand() % 800, h);
        h=h-22;
    }
    
    
    for (int t = 650; t<700; t++){
        aster[t] = new AsteroidObject("/Users/oliverhodge/Desktop/Game/Assets/rock5.png", rand() % 800, h);
        h=h-20;
    }
    
   
    for (int t = 700; t<750; t++){
        aster[t] = new AsteroidObject("/Users/oliverhodge/Desktop/Game/Assets/rock.png", rand() % 800, h);
        h=h-19;
    }
    
   
    for (int t = 750; t<800; t++){
        aster[t] = new AsteroidObject("/Users/oliverhodge/Desktop/Game/Assets/rock2.png", rand() % 800, h);
        h=h-18;
    }
    
    
    for (int t = 800; t<850; t++){
        aster[t] = new AsteroidObject("/Users/oliverhodge/Desktop/Game/Assets/rock3.png", rand() % 800, h);
        h=h-17;
    }
    
   
    for (int t = 850; t<900; t++){
        aster[t] = new AsteroidObject("/Users/oliverhodge/Desktop/Game/Assets/rock4.png", rand() % 800, h);
        h=h-16;
    }
    
    
    for (int t = 900; t<950; t++){
        aster[t] = new AsteroidObject("/Users/oliverhodge/Desktop/Game/Assets/rock5.png", rand() % 800, h);
        h=h-15;
    }
    
    
    for (int t = 950; t<1000; t++){
        aster[t] = new AsteroidObject("/Users/oliverhodge/Desktop/Game/Assets/rock.png", rand() % 800, h);
        h=h-14;
    }
    
    
    
    
    
    
    
    
    
    val = 0;
    
    
    
    
    
     
    
    
    
    
    
    
    
    map = new Map();
    
   
    
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
    
    
    
    if((ticks > 20000)&&(val<1)){
    int location = player->xval();
        rockstar[bigrock] = new BigFuckingRock("/Users/oliverhodge/Desktop/Game/Assets/rock.png", location-200, -200);
        bigrock++;
        val++;
    }
    if((ticks > 40000)&&(val<2)){
        int location = player->xval();
        rockstar[bigrock] = new BigFuckingRock("/Users/oliverhodge/Desktop/Game/Assets/rock.png", location-200, -200);
        bigrock++;
        val++;
    }
    if((ticks > 60000)&&(val<3)){
        int location = player->xval();
        rockstar[bigrock] = new BigFuckingRock("/Users/oliverhodge/Desktop/Game/Assets/rock.png", location-200, -200);
        bigrock++;
        val++;
    }
    if((ticks > 70000)&&(val<4)){
        int location = player->xval();
        rockstar[bigrock] = new BigFuckingRock("/Users/oliverhodge/Desktop/Game/Assets/rock.png", location-200, -200);
        bigrock++;
        val++;
    }
    if((ticks > 80000)&&(val<5)){
        int location = player->xval();
        rockstar[bigrock] = new BigFuckingRock("/Users/oliverhodge/Desktop/Game/Assets/rock.png", location-200, -200);
        bigrock++;
        val++;
    }
    if((ticks > 90000)&&(val<6)){
        int location = player->xval();
        rockstar[bigrock] = new BigFuckingRock("/Users/oliverhodge/Desktop/Game/Assets/rock.png", location-200, -200);
        bigrock++;
        val++;
    }
    if((ticks > 100000)&&(val<7)){
        int location = player->xval();
        rockstar[bigrock] = new BigFuckingRock("/Users/oliverhodge/Desktop/Game/Assets/rock.png", location-200, -200);
        bigrock++;
        val++;
    }
    if((ticks > 110000)&&(val<8)){
        int location = player->xval();
        rockstar[bigrock] = new BigFuckingRock("/Users/oliverhodge/Desktop/Game/Assets/rock.png", location-200, -200);
        bigrock++;
        val++;
    }
    if((ticks > 120000)&&(val<9)){
        int location = player->xval();
        rockstar[bigrock] = new BigFuckingRock("/Users/oliverhodge/Desktop/Game/Assets/rock.png", location-200, -200);
        bigrock++;
        val++;
    }
    if((ticks > 130000)&&(val<10)){
        int location = player->xval();
        rockstar[bigrock] = new BigFuckingRock("/Users/oliverhodge/Desktop/Game/Assets/rock.png", location-200, -200);
        bigrock++;
        val++;
    }
    if((ticks > 140000)&&(val<11)){
        int location = player->xval();
        rockstar[bigrock] = new BigFuckingRock("/Users/oliverhodge/Desktop/Game/Assets/rock.png", location-200, -200);
        bigrock++;
        val++;
    }
    if((ticks > 150000)&&(val<12)){
        int location = player->xval();
        rockstar[bigrock] = new BigFuckingRock("/Users/oliverhodge/Desktop/Game/Assets/rock.png", location-200, -200);
        bigrock++;
        val++;
    }
    if((ticks > 160000)&&(val<13)){
        int location = player->xval();
        rockstar[bigrock] = new BigFuckingRock("/Users/oliverhodge/Desktop/Game/Assets/rock.png", location-200, -200);
        bigrock++;
        val++;
    }
    if((ticks > 170000)&&(val<14)){
        int location = player->xval();
        rockstar[bigrock] = new BigFuckingRock("/Users/oliverhodge/Desktop/Game/Assets/rock.png", location-200, -200);
        bigrock++;
        val++;
    }
    if((ticks > 180000)&&(val<15)){
        int location = player->xval();
        rockstar[bigrock] = new BigFuckingRock("/Users/oliverhodge/Desktop/Game/Assets/rock.png", location-200, -200);
        bigrock++;
        val++;
    }
    if((ticks > 190000)&&(val<16)){
        int location = player->xval();
        rockstar[bigrock] = new BigFuckingRock("/Users/oliverhodge/Desktop/Game/Assets/rock.png", location-200, -200);
        bigrock++;
        val++;
    }if((ticks > 200000)&&(val<17)){
        int location = player->xval();
        rockstar[bigrock] = new BigFuckingRock("/Users/oliverhodge/Desktop/Game/Assets/rock.png", location-200, -200);
        bigrock++;
        val++;
    }
    if((ticks > 210000)&&(val<18)){
        int location = player->xval();
        rockstar[bigrock] = new BigFuckingRock("/Users/oliverhodge/Desktop/Game/Assets/rock.png", location-200, -200);
        bigrock++;
        val++;
    }
    if((ticks > 211000)&&(val<19)){
        int location = player->xval();
        rockstar[bigrock] = new BigFuckingRock("/Users/oliverhodge/Desktop/Game/Assets/rock.png", location-200, -200);
        bigrock++;
        val++;
    }
    if((ticks > 212000)&&(val<20)){
        int location = player->xval();
        rockstar[bigrock] = new BigFuckingRock("/Users/oliverhodge/Desktop/Game/Assets/rock.png", location-200, -200);
        bigrock++;
        val++;
    }
    if((ticks > 214000)&&(val<21)){
        int location = player->xval();
        rockstar[bigrock] = new BigFuckingRock("/Users/oliverhodge/Desktop/Game/Assets/rock.png", location-200, -200);
        bigrock++;
        val++;
    }
    if((ticks > 215000)&&(val<22)){
        int location = player->xval();
        rockstar[bigrock] = new BigFuckingRock("/Users/oliverhodge/Desktop/Game/Assets/rock.png", location-200, -200);
        bigrock++;
        val++;
    }
    if((ticks > 216000)&&(val<23)){
        int location = player->xval();
        rockstar[bigrock] = new BigFuckingRock("/Users/oliverhodge/Desktop/Game/Assets/rock.png", location-200, -200);
        bigrock++;
        val++;
    }
    if((ticks > 217000)&&(val<24)){
        int location = player->xval();
        rockstar[bigrock] = new BigFuckingRock("/Users/oliverhodge/Desktop/Game/Assets/rock.png", location-200, -200);
        bigrock++;
        val++;
    }
    if((ticks > 218000)&&(val<25)){
        int location = player->xval();
        rockstar[bigrock] = new BigFuckingRock("/Users/oliverhodge/Desktop/Game/Assets/rock.png", location-200, -200);
        bigrock++;
        val++;
    }
    if((ticks > 219000)&&(val<26)){
        int location = player->xval();
        rockstar[bigrock] = new BigFuckingRock("/Users/oliverhodge/Desktop/Game/Assets/rock.png", location-200, -200);
        bigrock++;
        val++;
    }
    if((ticks > 220000)&&(val<27)){
        int location = player->xval();
        rockstar[bigrock] = new BigFuckingRock("/Users/oliverhodge/Desktop/Game/Assets/rock.png", location-200, -200);
        bigrock++;
        val++;
    }
    if((ticks > 221000)&&(val<28)){
        int location = player->xval();
        rockstar[bigrock] = new BigFuckingRock("/Users/oliverhodge/Desktop/Game/Assets/rock.png", location-200, -200);
        bigrock++;
        val++;
    }
    if((ticks > 222000)&&(val<29)){
        int location = player->xval();
        rockstar[bigrock] = new BigFuckingRock("/Users/oliverhodge/Desktop/Game/Assets/rock.png", location-200, -200);
        bigrock++;
        val++;
    }
    if((ticks > 223000)&&(val<30)){
        int location = player->xval();
        rockstar[bigrock] = new BigFuckingRock("/Users/oliverhodge/Desktop/Game/Assets/rock.png", location-200, -200);
        bigrock++;
        val++;
    }
    if((ticks > 224000)&&(val<31)){
        int location = player->xval();
        rockstar[bigrock] = new BigFuckingRock("/Users/oliverhodge/Desktop/Game/Assets/rock.png", location-200, -200);
        bigrock++;
        val++;
    }
    if((ticks > 225000)&&(val<32)){
        int location = player->xval();
        rockstar[bigrock] = new BigFuckingRock("/Users/oliverhodge/Desktop/Game/Assets/rock.png", location-200, -200);
        bigrock++;
        val++;
    }
    if((ticks > 226000)&&(val<33)){
        int location = player->xval();
        rockstar[bigrock] = new BigFuckingRock("/Users/oliverhodge/Desktop/Game/Assets/rock.png", location-200, -200);
        bigrock++;
        val++;
    }
    if((ticks > 227000)&&(val<34)){
        int location = player->xval();
        rockstar[bigrock] = new BigFuckingRock("/Users/oliverhodge/Desktop/Game/Assets/rock.png", location-200, -200);
        bigrock++;
        val++;
    }
    if((ticks > 228000)&&(val<35)){
        int location = player->xval();
        rockstar[bigrock] = new BigFuckingRock("/Users/oliverhodge/Desktop/Game/Assets/rock.png", location-200, -200);
        bigrock++;
        val++;
    }
    if((ticks > 229000)&&(val<36)){
        int location = player->xval();
        rockstar[bigrock] = new BigFuckingRock("/Users/oliverhodge/Desktop/Game/Assets/rock.png", location-200, -200);
        bigrock++;
        val++;
    }if((ticks > 230000)&&(val<37)){
        int location = player->xval();
        rockstar[bigrock] = new BigFuckingRock("/Users/oliverhodge/Desktop/Game/Assets/rock.png", location-200, -200);
        bigrock++;
        val++;
    }
    if((ticks > 231000)&&(val<38)){
        int location = player->xval();
        rockstar[bigrock] = new BigFuckingRock("/Users/oliverhodge/Desktop/Game/Assets/rock.png", location-200, -200);
        bigrock++;
        val++;
    }
    if((ticks > 232000)&&(val<39)){
        int location = player->xval();
        rockstar[bigrock] = new BigFuckingRock("/Users/oliverhodge/Desktop/Game/Assets/rock.png", location-200, -200);
        bigrock++;
        val++;
    }
    if((ticks > 233000)&&(val<40)){
        int location = player->xval();
        rockstar[bigrock] = new BigFuckingRock("/Users/oliverhodge/Desktop/Game/Assets/rock.png", location-200, -200);
        bigrock++;
        val++;
    }
    
    
    
    
    
    
    if(ticks>1000000){
        std::cout<<"Stop playing this game: "<<std::endl;
        clean();
    }
     
    
    
    
    
    
    
    player->update();
    
    
    
    
    for (int t = 0; t<1000; t++){
        aster[t]->update();
    }
    
    if(rockstar[bigrock-1]!=NULL){rockstar[bigrock-1]->update();}
    
    
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
    
    
    if(rockstar[bigrock-1]!=NULL){rockstar[bigrock-1]->render();}
    
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
        if((h == 550)&&(((g<=(x+45)&&(g>=x)))||((g<=x)&&(g>=(x-45))))){
            
            collision = true;
            
        }
        
    }
    
    return collision;
}

bool Game::checkBigCollision(){
    
    int x = player->xval();
    
    for (int y = 0; y<1000; y++){
        
        int h = rockstar[bigrock-1]->yval();
        int g = rockstar[bigrock-1]->xval()+255;
        if((h==100)&&(((g<=(x+120)&&(g>=x)))||((g<=x)&&(g>=(x-120))))){
            
            BigCollision = true;
        }
    }
    return BigCollision;
}


