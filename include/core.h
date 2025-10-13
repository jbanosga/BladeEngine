#ifndef CORE_H
#define CORE_H

#include <vector>
#include <random>

#include <SDL3/SDL_events.h>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
#define LAZY_DELTA_TIME 0.01666

class Core 
{
public:
    ~Core();
    static Core* GetCoreInstance();

    void Initialize();
    void HandleInput(SDL_Event* event);
    void Update(double delta_time);
    void Draw(class SDL_Renderer* renderer);
    int GetRandom(int min, int max);

private:
    Core() {}

    static Core* core_instance_;
    //std::vector<class BaseRect*> character_list_;
    class Map* map_; 
    std::mt19937 random_generator_;
};


#endif