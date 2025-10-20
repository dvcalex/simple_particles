#include <iostream>

#include "glad_loader.h"
#include "window.h"

int main() 
{
    Window window{800, 600};

    GladLoader::load();

    window.startWindowLoop();

    return 0;
}
