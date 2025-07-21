#ifndef __CORE_H__
#define __CORE_H__

#include <vector>

class BaseCharacter;
class SDL_Renderer;

class Core 
{
public:
    ~Core();
    static Core* GetCoreInstance();

    void Initialize();
    void ActionLoop();
    void DrawLoop(SDL_Renderer* renderer);

private:
    Core() {}

    static Core* core_instance_;
    std::vector<BaseCharacter*> character_list_;
};

#endif