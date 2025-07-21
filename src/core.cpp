#include "core.h"
#include "base_character.h"

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
    BaseCharacter* aux_char = new BaseCharacter();
    aux_char->Init();

    character_list_.push_back(aux_char);
}

void Core::ActionLoop()
{
    
}

void Core::DrawLoop(SDL_Renderer* renderer)
{
    for (const auto& character : character_list_)
    {
        SDL_SetRenderDrawColor(renderer, 0, 0, 255, SDL_ALPHA_OPAQUE);
        SDL_RenderFillRect(renderer, character->GetCharacterBody());
    }
}