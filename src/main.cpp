#include <iostream>

#include "glad_loader.h"

#include "window.h"
#include "renderer.h"

int main()
{
    Window window(800, 600, "simple_particles");

    GladLoader::load();

    Renderer renderer;

    // start render loop
    window.startUpdating(
        // input callback
        []() {},
        // render callback
        [&renderer]() { renderer.renderLoopCallback(); }
    );

    return 0;
}
