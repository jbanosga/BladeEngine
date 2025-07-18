#ifndef __CORE_H__
#define __CORE_H__

class SDL_Renderer; 

class Core 
{
public:
    ~Core() {}
    static Core* GetCoreInstance();

    void SetRenderer(SDL_Renderer* r);
    SDL_Renderer* GetRenderer();

private:
    Core() {}

    static Core* core_instance_;
    SDL_Renderer* renderer_;
};

#endif