#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"
#include "glad/glad.h"
#include "MainImGuiFrame.h"

using namespace std;

int main()
{
	// Size of window
	int width = 720;
	int height = 360;	

	// Setup window
	if (!glfwInit())
		return 1;

	// GL 3.0 + GLSL 130
	const char* glsl_version = "#version 130";
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
	//glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  // 3.2+ only
	//glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);            // 3.0+ only

	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE); // Disable resizing

	// Create window with graphics context
	GLFWwindow* window = glfwCreateWindow(width, height, "Im0xDump", NULL, NULL);
	if (window == NULL)
		return 1;
	glfwMakeContextCurrent(window);
	glfwSwapInterval(1); // Enable vsync

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))  // Tie window context to glad's opengl funcs
		throw("Unable to context to OpenGL");

	int screen_width, screen_height;
	glfwGetFramebufferSize(window, &screen_width, &screen_height);
	glViewport(0, 0, screen_width, screen_height);

	MainImGuiFrame imGuiFrame;
	imGuiFrame.Init(window, glsl_version);
	while (!glfwWindowShouldClose(window)) {
		glfwPollEvents();

		imGuiFrame.NewFrame();
		imGuiFrame.Update();
		imGuiFrame.Render();
		glfwSwapBuffers(window);

		if (imGuiFrame.getClose()) {
			glfwSetWindowShouldClose(window, GLFW_TRUE);
		}
	}
	imGuiFrame.Shutdown();

	return 0;
}