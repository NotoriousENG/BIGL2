#include "Map.hpp"
#include "TextureManager.hpp"

int lvl1[20][25] = {
    
    //map
    //each int corresponds to a different image
    //allow for placing different tiles throughout map
    
    
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2}
};

Map::Map(){
    
    dirt = TextureManager::LoadTexture("/Users/oliverhodge/Desktop/Game/Assets/Sky.png");
    water = TextureManager::LoadTexture("/Users/oliverhodge/Desktop/Game/Assets/Sky.png");
    grass = TextureManager::LoadTexture("/Users/oliverhodge/Desktop/Game/Assets/Sky.png");
    loadMap(lvl1);
    src.x = src.y = 0;
    src.w = dest.w = 32;
    src.h = dest.h = 32;
    dest.x = dest.y = 0;
}

void Map::loadMap(int arr[20][25]){
    
    //nested for loops
    //loads the map
    //loads each row independently
    
    for(int row = 0; row<20; row++){
        for(int column = 0; column<25; column++){
            map[row][column]=arr[row][column];
        }
    }
    
}

void Map::drawMap(){
    
    int type = 0;
    
    //same logic used when loading map
    
    
    for(int row = 0; row<20; row++){
        for(int column = 0; column<25; column++){
            type = map[row][column];
            
            dest.x = column*32;
            dest.y = row*32;
            
            
            //allocates different type to each different case
            
            switch (type) {
                case 0:
                    TextureManager::draw(water, src, dest);
                    break;
                case 1:
                    TextureManager::draw(grass, src, dest);
                    break;
                case 2:
                    TextureManager::draw(dirt, src, dest);
                    break;
                    
                    
                default:
                    break;
            }
        }
    }
}
