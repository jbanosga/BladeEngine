#ifndef PLAYER_CHARACTER_H
#define PLAYER_CHARACTER_H

#include "base_rect.h"
#include <glm/ext/vector_float3.hpp>

class PlayerCharacter : public BaseRect
{
public:
    PlayerCharacter();
    ~PlayerCharacter();
    
    virtual void Init() override;
    void Init(float pos_x, float pos_y, float pos_z = 0.0f);
    virtual void ClearActions() override;
    virtual void Handle(uint32_t input) override;
    virtual void Update(double delta_time) override;
    virtual void Draw(SDL_Renderer* r) override;  
    
    virtual SDL_FRect* GetCharacterBody() override;
    virtual Transform* GetCharacterTransform() override;
    virtual BasicColor GetRectColor() override;
    virtual void SetRectColor(uint8_t r, uint8_t g, uint8_t b) override;

    void SetSpeed(float s);
    float GetSpeed();

protected:
    void UpdateBody();

    float speed_;
    glm::vec3 direction_;
};

#endif
