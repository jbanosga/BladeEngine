#include "base_rect.h"

#include <SDL3/SDL_rect.h>
#include <SDL3/SDL_render.h>

void BaseRect::Draw(SDL_Renderer* r)
{
    SDL_SetRenderDrawColor(r, body_color_.r, body_color_.g, body_color_.b, SDL_ALPHA_OPAQUE);
    SDL_RenderFillRect(r, body_);
}