#include "player_character.h"
#include "transform.h"

#include <SDL3/SDL_render.h>
#include <SDL3/SDL_rect.h>
#include <SDL3/SDL_keycode.h>

PlayerCharacter::PlayerCharacter()
{
    body_ = new SDL_FRect();
    transform_ = new Transform();
}

PlayerCharacter::~PlayerCharacter()
{
    if (body_)
    {
        delete body_;
        body_ = nullptr;
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
    transform_->position_.x = pos_x;
    transform_->position_.y = pos_y;
    transform_->position_.z = pos_z;
    
    speed_ = 0.0f;
    direction_ = glm::vec3(0.0f);

    body_color_ = { 0, 0, 255 };
    UpdateBody();
}

void PlayerCharacter::ClearActions()
{
    direction_ = glm::vec3(0.0f);
}

void PlayerCharacter::Handle(uint32_t input)
{
    switch (input)
    {
    case SDL_SCANCODE_W:
        direction_.y = -1.0f;
        break;
    case SDL_SCANCODE_S:
        direction_.y = 1.0f;
        break;
    }

    switch (input)
    {
    case SDL_SCANCODE_A:
        direction_.x = -1.0f;
        break;
    case SDL_SCANCODE_D:
        direction_.x = 1.0f;
        break;
    }
}

void PlayerCharacter::Update(double delta_time)
{   
    transform_->Translate(direction_ * speed_ * (float)delta_time);
    UpdateBody();
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
    body_->w = 10.0f * transform_->scale_.x;
    body_->h = 10.0f * transform_->scale_.y;
    body_->x = transform_->position_.x;
    body_->y = transform_->position_.y;
}