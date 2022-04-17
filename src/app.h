#pragma once

#include <GLFW/glfw3.h>

#include "scene.h"

class Application {
  public:
    Application(unsigned int width, unsigned int height);
    ~Application();

    unsigned int get_width();
    unsigned int get_height();
    GLFWwindow *get_window();

  private:
    unsigned int width;
    unsigned int height;
    GLFWwindow *window;
};