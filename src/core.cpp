#include "core.h"
#include "base_character.h"
#include "player_character.h"

#include <SDL3/SDL_render.h>


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

void Core::Initialize()
{
    PlayerCharacter* aux_char = new PlayerCharacter();
    aux_char->Init();
    aux_char->SetSpeed(1.0f);

    character_list_.push_back(aux_char);
}

void Core::HandleInput(SDL_Event* event)
{
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
}

void Core::Draw(SDL_Renderer* renderer)
{
    for (const auto& character : character_list_)
    {
        character->Draw(renderer);
    }
}