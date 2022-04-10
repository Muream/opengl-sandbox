#include "Renderer.h"

void Renderer::clear(float r, float g, float b) const {
    glClearColor(r, g, b, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Renderer::draw(VertexArray &vertexArray, IndexBuffer &indexBuffer, Shader &shader,
                    int drawType) const {
    vertexArray.bind();
    indexBuffer.bind();
    shader.bind();

    glDrawElements(drawType, 6, GL_UNSIGNED_INT, 0);
}
