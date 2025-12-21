#include "core/engine.h"

int main(void)
{
    engine_init();

    while (engine_running()) {
        engine_update();
        engine_render();
    }

    engine_shutdown();
    return 0;
}