#include "core.h"
#include "base_rect.h"
#include "player_character.h"
#include "transform.h"

#include <SDL3/SDL_render.h>
#include <SDL3/SDL_rect.h>


Core* Core::core_instance_ = nullptr;

Core::~Core()
{
    character_list_.clear();
}

Core* Core::GetCoreInstance()
{
    if (core_instance_ == nullptr)
    {
        core_instance_ = new Core();
    }

    return core_instance_;
}

int Core::GetRandom(int min, int max)
{
    std::uniform_int_distribution<uint32_t> distribute(min, max);
    return distribute(random_generator_);
}

void Core::Initialize()
{
    std::random_device os_seed;
    const uint32_t seed = os_seed();
    random_generator_ = std::mt19937(seed);
    

    CreateMapGrid();
}

void Core::HandleInput(SDL_Event* event)
{
    for (const auto& character: character_list_)
    {
        character->ClearActions();
    }

    if (event->type == SDL_EVENT_KEY_DOWN)
    {
        for (const auto& character: character_list_)
        {
            character->Handle(event->key.scancode);
        }
    }
}

void Core::Update(double delta_time)
{   
    for (const auto& character: character_list_)
    {
        character->Update(delta_time);
    }

    for (const auto& tile: map_grid_)
    {
	    tile->Update(delta_time);
    }
}

void Core::Draw(SDL_Renderer* renderer)
{
    for (const auto& character : character_list_)
    {
        character->Draw(renderer);
    }

    for (const auto& tile : map_grid_)
    {
        tile->Draw(renderer);
    }
}


void Core::CreateMapGrid()
{
    constexpr uint8_t map_width = 10;
    constexpr uint8_t map_height = 10;
    const uint8_t tile_dimension = 45; 
    for (uint8_t i = 0; i < map_width; i++)
    {
        for (uint8_t j = 0; j < map_height; j++)
        {
            //auto index = j + (i * map_width);
            PlayerCharacter* tile = new PlayerCharacter();
            tile->Init(tile_dimension * j, tile_dimension * i);
	        tile->GetCharacterTransform()->scale_.x = tile_dimension * 0.1f;
	        tile->GetCharacterTransform()->scale_.y = tile_dimension * 0.1f;
	        tile->SetRectColor(GetRandom(0, 255), GetRandom(0, 255), GetRandom(0,255));
            map_grid_.push_back(tile);
        }
    }

}
