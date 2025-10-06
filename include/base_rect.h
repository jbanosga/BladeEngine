#ifndef BASE_RECT_H
#define BASE_RECT_H

#include "common_def.h"

struct BasicColor
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
};

class BaseRect
{
public:
    virtual void Init() = 0;
    virtual void ClearActions() = 0;
    virtual void Handle(uint32_t input) = 0;
    virtual void Update(double delta_time) = 0;
    virtual void Draw(class SDL_Renderer* r) = 0;
    virtual class SDL_FRect* GetCharacterBody() = 0;
    virtual class Transform* GetCharacterTransform() = 0;
    virtual BasicColor GetRectColor() = 0;
    virtual void SetRectColor(uint8_t r, uint8_t g, uint8_t b) = 0;

protected:
    class SDL_FRect* character_body_ = nullptr;
    class Transform* transform_ = nullptr;
    BasicColor rect_color_;
};

#endif
