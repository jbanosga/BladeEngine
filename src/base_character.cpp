#include "base_character.h"

#include <SDL3/SDL_rect.h>
#include <SDL3/SDL_render.h>

BaseCharacter::BaseCharacter()
{
    character_body_ = nullptr;
}


BaseCharacter::~BaseCharacter()
{
    if (character_body_)
    {
        delete character_body_;
        character_body_ = nullptr;
    }
}

void BaseCharacter::Init()
{
    character_body_ = new SDL_FRect();
    character_body_->h = 280.0f;
    character_body_->w = 440.0f;
    character_body_->x = 100.0f;
    character_body_->y = 100.0f;
}

SDL_FRect* BaseCharacter::GetCharacterBody()
{
    return character_body_;
}

void BaseCharacter::DrawBody(SDL_Renderer* r)
{
    
}