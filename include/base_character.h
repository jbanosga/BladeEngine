#ifndef __BASE_CHARACTER_H__
#define __BASE_CHARACTER_H__

#include <SDL3/SDL_keycode.h>

class SDL_FRect;

class BaseCharacter
{
public:
    BaseCharacter();
    ~BaseCharacter();

    void Init();
    SDL_FRect* GetCharacterBody();

    void Handle(SDL_Keycode input);
    void Update(float delta_time);
    void Draw();

protected:
    SDL_FRect* character_body_;

};

#endif