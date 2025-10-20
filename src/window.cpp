#include "window.h"

#include <iostream>
#include <cstdlib>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

Window::Window(int width, int height, std::string_view title)
	: window(nullptr)
{
	glfwSetErrorCallback([](int error, const char* description) {
		std::cout << "GLFW Error " << error << ": " << description << std::endl;
	});

	if (!glfwInit())
	{
		std::cout << "Could not initialize GLFW" << std::endl;
		std::exit(1);
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef MAC_OS
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

	window = glfwCreateWindow(width, height, title.data(), nullptr, nullptr);
	if (window == nullptr)
	{
		std::cout << "Could not create GLFW window" << std::endl;
		glfwTerminate();
		std::exit(1);
	}

	glfwMakeContextCurrent(window);

	glfwSetFramebufferSizeCallback(window, framebufferSizeCallback);
}

Window::~Window()
{
	if (window)
	{
		glfwDestroyWindow(window);
	}
	glfwTerminate();
}

bool Window::shouldClose() const
{
	return glfwWindowShouldClose(window);
}

void Window::framebufferSizeCallback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}