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
    virtual void Init() {}
    virtual void Update(double delta_time) {} 
    virtual void Draw(class SDL_Renderer* r);
    virtual inline class SDL_FRect* GetBody() { return body_; }
    virtual inline class Transform* GetTransform() { return transform_; }
    virtual inline BasicColor GetRectColor() { return body_color_; } 
    virtual inline void SetRectColor(uint8_t r, uint8_t g, uint8_t b) { body_color_.r = r; body_color_.g = g; body_color_.b; }

protected:
    class SDL_FRect* body_ = nullptr;
    class Transform* transform_ = nullptr;
    BasicColor body_color_;
};

#endif
