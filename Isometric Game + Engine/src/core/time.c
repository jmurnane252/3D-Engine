#include "time.h"
#include <SDL3/SDL.h>

static Uint64 last_ticks;
static float delta;

#define FIXED_STEP (1.0f / 60.0f)

void time_init(void)
{
    last_ticks = SDL_GetTicks();
}

void time_update(void)
{
    Uint64 current = SDL_GetTicks();
    Uint64 elapsed = current - last_ticks;

    delta = elapsed / 1000.0f;
    last_ticks = current;
}

float time_delta(void)
{
    return delta;
}

float time_fixed_step(void)
{
    return FIXED_STEP;
}
