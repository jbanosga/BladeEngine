#include "player_character.h"

#include <SDL3/SDL_render.h>
#include <SDL3/SDL_rect.h>
#include <SDL3/SDL_keycode.h>

PlayerCharacter::PlayerCharacter()
{
    character_body_ = nullptr;
}

PlayerCharacter::~PlayerCharacter()
{
    if (character_body_)
    {
        delete character_body_;
        character_body_ = nullptr;
    }
}

void PlayerCharacter::Init()
{
    character_body_ = new SDL_FRect();
    character_body_->h = 280.0f;
    character_body_->w = 440.0f;
    character_body_->x = 100.0f;
    character_body_->y = 100.0f;
}

void PlayerCharacter::Handle(uint32_t input)
{

    switch (input)
    {
    case SDL_SCANCODE_W:
        break;
    case SDL_SCANCODE_S:
        break;
    case SDL_SCANCODE_A:
        break;
    case SDL_SCANCODE_D:
        break;
        default:
        break;
    }
}

void PlayerCharacter::Update(double delta_time)
{

}

void PlayerCharacter::Draw(SDL_Renderer* r)
{

}

SDL_FRect* PlayerCharacter::GetCharacterBody()
{
    return character_body_;
}
