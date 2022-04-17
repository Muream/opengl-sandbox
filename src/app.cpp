#include <iostream>

#include <glad/glad.h>

#include <GLFW/glfw3.h>

#include "app.h"
#include "gl_utils.h"

Application::Application(unsigned int width, unsigned int height)
    : width(width), height(height) {

    glfwSetErrorCallback([](int error, const char *description) {
        fprintf(stderr, "Error: %s\n", description);
    });

    /* Initialize the library */
    glfwInit();
    // if (!glfwInit())
    //    return -1;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(width, height, "OpenGL Sandbox", nullptr, nullptr);

    if (!window) {
        glfwTerminate();
        // return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    gladLoadGL();

    glDebugMessageCallback(opengl_message_callback, nullptr);
}

Application::~Application() {}

unsigned int Application::get_width() { return width; }

unsigned int Application::get_height() { return height; }

GLFWwindow *Application::get_window() { return window; }

