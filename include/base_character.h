#ifndef __BASE_CHARACTER_H__
#define __BASE_CHARACTER_H__

class SDL_FRect;
class SDL_Renderer;

class BaseCharacter
{
public:
    BaseCharacter();
    ~BaseCharacter();

    void Init();
    SDL_FRect* GetCharacterBody();

    void DrawBody(SDL_Renderer* r);

protected:
    SDL_FRect* character_body_;
};

#endif