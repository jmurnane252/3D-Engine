#include "engine.h"
#include "window.h"
#include <stdio.h>

static int running = 0;

void engine_init(void) 
{
    printf("[Engine] Initializing...\n");
    running = 1;

    // Initialize window
    window_init(800, 600, "Isometric Engine");

    if (!window_is_open()) {
        printf("[Engine] Failed to create window. Exiting...\n");
        running = 0;
    }  
}

int engine_running(void)
{
    // Engine runs while window is open and user hasn't closed
    return running && window_is_open() && !window_should_close();
}

void engine_update(void) 
{
    window_poll_events();

    if (window_should_close()) {
        running = 0;
    }

    // Later have game logic, updated every frame

}

void engine_render(void) 
{
    // Clears screen, draws tiles, entities

}

void engine_shutdown(void)
{
    printf("[Engine] Shutting down...\n");
    window_shutdown();
    running = 0;
}

