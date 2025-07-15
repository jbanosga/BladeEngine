#ifndef __BASE_CHARACTER_H__
#define __BASE_CHARACTER_H__

class SDL_FRect;

class BaseCharacter
{
public:
    BaseCharacter();
    BaseCharacter(float pos_x, float pos_y, float width, float height);
    ~BaseCharacter();

protected:
    SDL_FRect* character_body_;
    
}

#endif;