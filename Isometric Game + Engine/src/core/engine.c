#include "engine.h"
#include "window.h"
#include "time.h"
#include <stdio.h>

static int tick_count = 0;
static float tick_timer = 0.0f;
static int running = 0;
static float accumulator = 0.0f;

void engine_init(void) 
{
    printf("[Engine] Initializing...\n");
    running = 1;

    // Initialize window
    window_init(800, 600, "Isometric Engine");

    // Initialize time
    time_init();

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
    time_update();

    accumulator += time_delta();
    tick_timer += time_delta();

    while (accumulator >= time_fixed_step()) {
        tick_count++;
        accumulator -= time_fixed_step();
    }

    if (tick_timer >= 1.0f) {
        printf("Logic ticks per second: %d\n", tick_count);
        tick_count = 0;
        tick_timer = 0.0f;
    }

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

