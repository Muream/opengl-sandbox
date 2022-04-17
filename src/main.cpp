#include <iostream>
#include <stdio.h>
#include <vector>

#include <glad/glad.h>

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

#include "app.h"

#include "index_buffer.h"
#include "mesh.h"
#include "renderer.h"
#include "shader.h"
#include "vertex.h"
#include "vertex_array.h"
#include "vertex_buffer.h"

int main(void) {
    Application app(1280, 720);

    // Create a scope to delete OpenGL Objects before the context gets invalid
    {
        std::vector<Vertex> vertices = {
            Vertex{glm::vec3(0.5f, 0.5f, 0.0f)},   // top right
            Vertex{glm::vec3(0.5f, -0.5f, 0.0f)},  // bottom right
            Vertex{glm::vec3(-0.5f, -0.5f, 0.0f)}, // bottom left
            Vertex{glm::vec3(-0.5f, 0.5f, 0.0f)}   // top left
        };
        std::vector<unsigned int> indices = {
            0, 1, 3, // first triangle
            1, 2, 3  // second triangle
        };
        Mesh mesh(vertices, indices);

        glm::mat4 projectionMatrix = glm::ortho(
            -(float)app.get_width() / 200.0f, (float)app.get_width() / 200.0f,
            -(float)app.get_height() / 200.0f, (float)app.get_height() / 200.0f, -1.0f,
            1.0f);

        Shader shader("resources/shaders/basic.shader");
        shader.bind();
        shader.set_uniform_3f("color", 0.1, 0.6, 1.0);
        shader.set_uniform_mat4("mvp", projectionMatrix);

        Renderer renderer;

        /* Loop until the user closes the window */
        while (!glfwWindowShouldClose(app.get_window())) {
            renderer.clear(0.1, 0.1, 0.1);

            renderer.draw(mesh, shader);

            /* Swap front and back buffers */
            glfwSwapBuffers(app.get_window());

            /* Poll for and process events */
            glfwPollEvents();
        }
    }
    glfwTerminate();
    return 0;
}