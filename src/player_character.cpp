#include "player_character.h"
#include "transform.h"

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

    if (transform_)
    {
        delete transform_;
        transform_ = nullptr;
    }
}

void PlayerCharacter::Init()
{
    Init(0.0f, 0.0f, 0.0f);
}

void PlayerCharacter::Init(float pos_x, float pos_y, float pos_z)
{
    transform_ = new Transform();
    transform_->position_.x = pos_x;
    transform_->position_.y = pos_y;
    transform_->position_.z = pos_z;

    character_body_ = new SDL_FRect();
    UpdateBody();

    speed_ = 0.0f;
    direction_ = glm::vec3(0.0f);
}

void PlayerCharacter::Handle(uint32_t input)
{
    direction_ = glm::vec3(0.0f);
    switch (input)
    {
    case SDL_SCANCODE_W:
        direction_.y = -1.0f;
        break;
    case SDL_SCANCODE_S:
        direction_.y = 1.0f;
        break;
    case SDL_SCANCODE_A:
        direction_.x = -1.0f;
        break;
    case SDL_SCANCODE_D:
        direction_.x = 1.0f;
        break;
    default:
        direction_ = glm::vec3(0.0f);
        break;
    }
}

void PlayerCharacter::Update(double delta_time)
{   
    transform_->Translate(direction_ * speed_ * (float)delta_time);
    UpdateBody();
}

void PlayerCharacter::Draw(SDL_Renderer* r)
{
    SDL_SetRenderDrawColor(r, 0, 0, 255, SDL_ALPHA_OPAQUE);
    SDL_RenderFillRect(r, character_body_);
}

SDL_FRect* PlayerCharacter::GetCharacterBody()
{
    return character_body_;
}

Transform* PlayerCharacter::GetCharacterTransform()
{
    return transform_;
}

void PlayerCharacter::SetSpeed(float s)
{
    speed_ = s;
}

float PlayerCharacter::GetSpeed()
{
    return speed_;
}

void PlayerCharacter::UpdateBody()
{
    character_body_->w = 100.0f * transform_->scale_.x;
    character_body_->h = 100.0f * transform_->scale_.y;
    character_body_->x = transform_->position_.x;
    character_body_->y = transform_->position_.y;
}