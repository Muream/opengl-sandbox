#include "renderer.h"
#include "mesh.h"

void Renderer::clear(float r, float g, float b) const {
    glClearColor(r, g, b, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Renderer::draw(Mesh &mesh, Shader &shader, int drawType) const {
    shader.bind();

    mesh.get_vertex_array().bind();
    mesh.get_index_buffer().bind();

    glDrawElements(drawType, mesh.get_index_buffer().get_count(), GL_UNSIGNED_INT,
                   nullptr);
}
