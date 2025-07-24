#ifndef __CORE_H__
#define __CORE_H__

#include <vector>

#include <SDL3/SDL_events.h>

class BaseCharacter;
class SDL_Renderer;

class Core 
{
public:
    ~Core();
    static Core* GetCoreInstance();

    void Initialize();
    void HandleInput(SDL_Event* event);
    void Update(double delta_time);
    void Draw(SDL_Renderer* renderer);

private:
    Core() {}

    static Core* core_instance_;
    std::vector<BaseCharacter*> character_list_;
};

#endif