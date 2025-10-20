#pragma once

#include <string_view>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Window
{
public:
	Window(int width, int height, std::string_view title = "simple_particles");
	~Window();

	GLFWwindow* getGLFWwindow() const { return window; }

	template<typename InputCallback, typename RenderCallback>
	void startUpdating(InputCallback inputCallback, RenderCallback renderCallback)
	{
		while (!this->shouldClose())
		{
			// Process input
			inputCallback();

			// Render
			renderCallback();

			// Swap buffers and poll events
			glfwSwapBuffers(window);
			glfwPollEvents();
		}
	}

private:
	static void framebufferSizeCallback(GLFWwindow* window, int width, int height);
	bool shouldClose() const;

private:
	GLFWwindow* window; // raw pointer because C library
};