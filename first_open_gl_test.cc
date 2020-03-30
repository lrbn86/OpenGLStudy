#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
using namespace std;
void init(GLFWwindow* window) { }
void display(GLFWwindow* window, double currentTime) {
glClearColor(1.0, 0.0, 0.0, 1.0);
glClear(GL_COLOR_BUFFER_BIT);
}
int main(void) {
if (!glfwInit()) { exit(EXIT_FAILURE); }

// Use the highest OpenGL version supported by OS
// https://stackoverflow.com/questions/19865463/opengl-4-1-under-mavericks
glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);

GLFWwindow* window = glfwCreateWindow(600, 600, "Chapter2 - program1", NULL, NULL);
glfwMakeContextCurrent(window);
if (glewInit() != GLEW_OK) { exit(EXIT_FAILURE); }
glfwSwapInterval(1);
init(window);
while (!glfwWindowShouldClose(window)) {
display(window, glfwGetTime());
glfwSwapBuffers(window);
glfwPollEvents();
}
cout << glGetString(GL_VERSION);
glfwDestroyWindow(window);
glfwTerminate();
exit(EXIT_SUCCESS);
}
