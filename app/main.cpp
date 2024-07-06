#include <iostream>

#include "GL/glew.h"
#include "GLFW/glfw3.h"

//namespace cs = cyan::ShaderLib;
//namespace cst = cyan::ShaderLib;

void error_callback(int error, const char* description)
{
	fprintf(stderr, "Error: %s\n", description);
}
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}
void processInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}


int width = 1000;
int height = 600;
	
int main(int argc, char* argv[]) {
	std::cout << "hello world" << std::endl;

	if (!glfwInit())
	{
		std::cout << "glfw init failed" << std::endl;
		glfwTerminate();
	}

	glfwSetErrorCallback(error_callback);

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	GLFWwindow* window = glfwCreateWindow(width, height, "test", NULL, NULL);
	if (!window)
	{
		std::cout << "window init failed" << std::endl;
	}
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	glfwMakeContextCurrent(window);

	glewExperimental = GL_TRUE;
	GLenum err = glewInit();
	if (GLEW_OK != err)
	{
		std::cout << "glew init failed: " << glewGetErrorString(err) << std::endl;
	}

	std::cout << "Set up success" << std::endl;

	glViewport(0, 0, width, height);

	while (!glfwWindowShouldClose(window))
	{
		processInput(window);

		glClearColor(0.2f, 0.3f, 0.3f, 0.6f);
		glClear(GL_COLOR_BUFFER_BIT);

        //gl

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwDestroyWindow(window);
	glfwTerminate();

	return EXIT_SUCCESS;
}