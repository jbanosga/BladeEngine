#ifndef MAP_H
#define MAP_H

#include "base_rect.h"

#include <vector>

class MapTile : public BaseRect
{
public:
    MapTile(); 
    ~MapTile();
};

class Map 
{
public:
    Map();
    Map(int map_dimension);
    ~Map();

    void DrawMap(class SDL_Renderer* r);
    
private:
    std::vector<MapTile*> map_tiles_;
};

#endif