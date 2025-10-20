#pragma once

#include <string_view>

class GLFWwindow;

class Window
{
public:
	Window(int width, int height, std::string_view title = "simple_particles");
	~Window();

	//GLFWwindow* getGLFWwindow() const { return window; }
	void startWindowLoop();

private:
	static void framebufferSizeCallback(GLFWwindow* window, int width, int height);
	bool shouldClose() const;

private:
	GLFWwindow* window; // raw pointer because C library
};