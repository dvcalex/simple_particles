#include "glad_loader.h"

#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

void GladLoader::load()
{
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Could not initialize GLAD" << std::endl;
        std::exit(1);
    }
}