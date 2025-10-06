#ifndef CORE_H
#define CORE_H

#include <vector>
#include <random>

#include <SDL3/SDL_events.h>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
#define LAZY_DELTA_TIME 0.01666

class BaseRect;
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
    int GetRandom(int min, int max);

private:
    Core() {}

    void CreateMapGrid();

    static Core* core_instance_;
    std::vector<BaseRect*> character_list_;
    std::vector<BaseRect*> map_grid_;
    std::mt19937 random_generator_;
};


#endif