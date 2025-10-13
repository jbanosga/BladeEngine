#include "map.h"
#include "transform.h"
#include "core.h"

#include <SDL3/SDL_rect.h>
#include <SDL3/SDL_render.h>

MapTile::MapTile()
{
    body_ = new SDL_FRect();
    transform_ = new Transform();
}

MapTile::~MapTile()
{
    delete body_;
    body_ = nullptr;
    delete transform_;
    transform_ = nullptr;
}

Map::Map()
{
}

Map::Map(int map_dimension)
{
    Core* core_ref = Core::GetCoreInstance(); 
    constexpr uint8_t map_width = 10;
    constexpr uint8_t map_height = 10;
    const uint8_t tile_dimension = 45;
    for (uint8_t i = 0; i < map_width; i++)
    {
        for (uint8_t j = 0; j < map_height; j++)
        {
            // auto index = j + (i * map_width);
            MapTile* tile = new MapTile();
            tile->GetTransform()->position_.x = j;
            tile->GetTransform()->position_.y = i;
            tile->GetTransform()->position_.z = 0.0f;

            tile->GetTransform()->scale_.x = tile_dimension * 10.0f;
            tile->GetTransform()->scale_.y = tile_dimension * 10.0f;
            tile->SetRectColor(core_ref->GetRandom(0, 255), core_ref->GetRandom(0, 255),
                               core_ref->GetRandom(0, 255));
            map_tiles_.push_back(tile);
        }
    }
}

Map::~Map()
{
    map_tiles_.clear();
}

void Map::DrawMap(SDL_Renderer* r)
{
    for (const auto& tile : map_tiles_)
    {
        tile->Draw(r);
    }
}