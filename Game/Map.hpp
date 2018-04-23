#include <stdio.h>

#include "Game.hpp"

class Map{
    
public:
    
    //map constructor
    Map();
    
    //map destructor
    ~Map();
    
    //loads map into an array of 20 rows and 25columns
    //map can be edited in map.cpp class
    //allows for possibility to create several tiles in the background
    
    void loadMap(int arr[20][25]);
    
    //draws map to window
    void drawMap();
    
    
    
private:
    
    SDL_Rect src, dest;
    SDL_Texture* dirt;
    SDL_Texture* grass;
    SDL_Texture* water;
    
    int map[20][25];
    
    
    
};

