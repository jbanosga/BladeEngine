#ifndef __PLAYER_CHARACTER_H__
#define __PLAYER_CHARACTER_H__

#include "base_character.h"

class PlayerCharacter : public BaseCharacter
{
public:
    PlayerCharacter();
    ~PlayerCharacter();
    
    virtual void Init() override;
    virtual void Handle(uint32_t input) override;
    virtual void Update(double delta_time) override;
    virtual void Draw(SDL_Renderer* r) override;  
    
    virtual SDL_FRect* GetCharacterBody() override;
};

#endif