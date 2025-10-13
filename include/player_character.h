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
    void ClearActions();
    void Handle(uint32_t input);
    void Update(double delta_time);
    
    void SetSpeed(float s);
    float GetSpeed();

protected:
    void UpdateBody();

    float speed_;
    glm::vec3 direction_;
};

#endif
