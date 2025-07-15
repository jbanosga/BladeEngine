#include "base_character.h"

#include <SDL3/SDL.h>

BaseCharacter::BaseCharacter()
{
    character_body_ = nullptr;
}

BaseCharacter::BaseCharacter(float pos_x, float pos_y, float width, float height)
{
    
}

BaseCharacter::~BaseCharacter()
{
    if (character_body_)
    {
        delete character_body_;
        character_body_ = nullptr;
    }
}