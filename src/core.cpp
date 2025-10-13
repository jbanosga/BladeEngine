#include "core.h"
#include "base_rect.h"
#include "player_character.h"
#include "transform.h"
#include "map.h"

#include <SDL3/SDL_rect.h>
#include <SDL3/SDL_render.h>

Core *Core::core_instance_ = nullptr;

Core::~Core()
{
  // character_list_.clear();
  if (map_ != nullptr)
  {
    delete map_;
    map_ = nullptr;
  }
}

Core *Core::GetCoreInstance()
{
  if (core_instance_ == nullptr)
  {
    core_instance_ = new Core();
  }

  return core_instance_;
}

int Core::GetRandom(int min, int max)
{
  std::uniform_int_distribution<uint32_t> distribute(min, max);
  return distribute(random_generator_);
}

void Core::Initialize()
{
  std::random_device os_seed;
  const uint32_t seed = os_seed();
  random_generator_ = std::mt19937(seed);
  map_ = new Map(35);
}

void Core::HandleInput(SDL_Event *event)
{
}

void Core::Update(double delta_time)
{
  // for (const auto &character : character_list_)
  //{
  //  character->Update(delta_time);
  // }
}

void Core::Draw(SDL_Renderer *renderer)
{
  // for (const auto &character : character_list_)
  //{
  //   character->Draw(renderer);
  // }

  map_->DrawMap(renderer);
}
