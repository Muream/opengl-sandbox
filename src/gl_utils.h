#pragma once
#include <glad/glad.h>
#include <iostream>

void opengl_message_callback(unsigned source, unsigned type, unsigned id,
                           unsigned severity, int length, const char *message,
                           const void *userParam) {
    std::cout << message << std::endl;
}