#include "mesh.h"

Mesh::Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices)
    : vertex_buffer(vertices),
      index_buffer(indices),
      matrix(glm::mat4(1.0f))
{
    layout.push<float>(3); // position attribute
    vertex_array.add_buffer(vertex_buffer, layout);
}

Mesh::~Mesh() {
    vertex_buffer.~VertexBuffer();
    vertex_array.~VertexArray();
    index_buffer.~IndexBuffer();
}

VertexArray &Mesh::get_vertex_array() { return vertex_array; }
IndexBuffer &Mesh::get_index_buffer() { return index_buffer; }
