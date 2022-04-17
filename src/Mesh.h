#pragma once

#include <glm/glm.hpp>

#include "index_buffer.h"
#include "vertex.h"
#include "vertex_array.h"
#include "vertex_buffer.h"
#include "vertex_buffer_layout.h"

class Mesh {
  public:
    Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices);
    ~Mesh();

    VertexArray &get_vertex_array();
    IndexBuffer &get_index_buffer();

  private:
    IndexBuffer index_buffer;
    VertexArray vertex_array;
    VertexBuffer vertex_buffer;
    VertexBufferLayout layout;
    glm::mat4 matrix;
};
