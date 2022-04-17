#pragma once
#include <glad/glad.h>

#include "index_buffer.h"
#include "mesh.h"
#include "shader.h"
#include "vertex_array.h"

class Renderer {
  private:
  public:
    void clear(float r, float g, float b) const;
    void draw(Mesh &mesh, Shader &shader, int draw_type = GL_TRIANGLES) const;
};
