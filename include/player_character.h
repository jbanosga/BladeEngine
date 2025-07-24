#ifndef __PLAYER_CHARACTER_H__
#define __PLAYER_CHARACTER_H__

#include "base_character.h"
#include <glm/ext/vector_float3.hpp>

class PlayerCharacter : public BaseCharacter
{
public:
    PlayerCharacter();
    ~PlayerCharacter();
    
    virtual void Init() override;
    void Init(float pos_x, float pos_y, float pos_z = 0.0f);
    virtual void Handle(uint32_t input) override;
    virtual void Update(double delta_time) override;
    virtual void Draw(SDL_Renderer* r) override;  
    
    virtual SDL_FRect* GetCharacterBody() override;
    virtual Transform* GetCharacterTransform() override;

    void SetSpeed(float s);
    float GetSpeed();

protected:
    void UpdateBody();

    float speed_;
    glm::vec3 direction_;
};

#endif