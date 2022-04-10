#include <iostream>
#include <stdio.h>
#include <vector>

#include <glad/glad.h>

#include <GLFW/glfw3.h>

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

#include "GLUtils.h"
#include "IndexBuffer.h"
#include "Renderer.h"
#include "Shader.h"
#include "VertexArray.h"
#include "VertexBuffer.h"

int main(void) {
    glfwSetErrorCallback([](int error, const char *description) {
        fprintf(stderr, "Error: %s\n", description);
    });

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    /* Create a windowed mode window and its OpenGL context */
    GLFWwindow *window;

    unsigned int SCREEN_WIDTH = 1280;
    unsigned int SCREEN_HEIGHT = 720;
    window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "OpenGL Sandbox", nullptr,
                              nullptr);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    gladLoadGL();

    glDebugMessageCallback(OpenGLMessageCallback, nullptr);

    // Create a scope to delete OpenGL Objects before the context gets invalid
    {

        float vertices[] = {
            0.5f,  0.5f,  0.0f, // top right
            0.5f,  -0.5f, 0.0f, // bottom right
            -0.5f, -0.5f, 0.0f, // bottom left
            -0.5f, 0.5f,  0.0f  // top left
        };

        unsigned int indices[] = {
            0, 1, 3, // first triangle
            1, 2, 3  // second triangle
        };

        VertexBuffer vertexBuffer(vertices, 4 * 3 * sizeof(float));
        VertexBufferLayout layout;

        VertexArray vertexArray;
        layout.push<float>(3);
        vertexArray.addBuffer(vertexBuffer, layout);

        IndexBuffer indexBuffer(indices, 6);

        glm::mat4 projectionMatrix = glm::ortho(
            -(float)SCREEN_WIDTH / 200.0f, (float)SCREEN_WIDTH / 200.0f,
            -(float)SCREEN_HEIGHT / 200.0f, (float)SCREEN_HEIGHT / 200.0f, -1.0f, 1.0f);
        // glm::mat4 projectionMatrix = glm::perspective(glm::radians(50.0f),
        // (float)SCREEN_WIDTH / (float)SCREEN_HEIGHT, 0.1f, 100.0f); glm::mat4
        // projectionMatrix;

        Shader shader("resources/shaders/basic.shader");
        shader.bind();
        shader.setUniform3f("color", 0.1, 0.6, 1.0);
        shader.setUniformMat4("mvp", projectionMatrix);

        Renderer renderer;

        /* Loop until the user closes the window */
        while (!glfwWindowShouldClose(window)) {
            renderer.clear(0.1, 0.1, 0.1);

            renderer.draw(vertexArray, indexBuffer, shader);

            /* Swap front and back buffers */
            glfwSwapBuffers(window);

            /* Poll for and process events */
            glfwPollEvents();
        }
    }
    glfwTerminate();
    return 0;
}