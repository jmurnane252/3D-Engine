#include "window.h"
#include <SDL3/SDL.h>

static SDL_Window* window = NULL;
static int should_close = 0;

void window_init(int width, int height, const char* title)
{
    if (SDL_Init(SDL_INIT_VIDEO) != 1) {
        SDL_Log("SDL_Init Error: %s", SDL_GetError());
        return;
    }

    window = SDL_CreateWindow(
        title,
        width,
        height,
        0 // no flags yet
    );
}

void window_poll_events(void)
{
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_EVENT_QUIT) {
            should_close = 1;
        }
    }
}

int window_is_open(void)
{
    return window != NULL;
}

int window_should_close(void)
{
    return should_close;
}

void window_shutdown(void)
{
    if (window) SDL_DestroyWindow(window);
    SDL_Quit();
}
