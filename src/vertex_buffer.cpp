#include "vertex_buffer.h"

VertexBuffer::VertexBuffer(std::vector<Vertex> vertices) {
    glGenBuffers(1, &renderer_id);
    glBindBuffer(GL_ARRAY_BUFFER, renderer_id);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), &vertices[0],
                 GL_STATIC_DRAW);
}

VertexBuffer::~VertexBuffer() { glDeleteBuffers(1, &renderer_id); }

void VertexBuffer::bind() const { glBindBuffer(GL_ARRAY_BUFFER, renderer_id); }

void VertexBuffer::unbind() const { glBindBuffer(GL_ARRAY_BUFFER, 0); }
