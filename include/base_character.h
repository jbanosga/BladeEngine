#ifndef __BASE_CHARACTER_H__
#define __BASE_CHARACTER_H__

#include "common_def.h"

class BaseCharacter
{
public:
    virtual void Init() = 0;
    virtual void ClearActions() = 0;
    virtual void Handle(uint32_t input) = 0;
    virtual void Update(double delta_time) = 0;
    virtual void Draw(class SDL_Renderer* r) = 0;
    virtual class SDL_FRect* GetCharacterBody() = 0;
    virtual class Transform* GetCharacterTransform() = 0;
    
protected:
    class SDL_FRect* character_body_ = nullptr;
    class Transform* transform_ = nullptr;
};

#endif