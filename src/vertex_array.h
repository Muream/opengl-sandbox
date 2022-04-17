#pragma once
#include "vertex_buffer.h"
#include "vertex_buffer_layout.h"

class VertexArray {
  private:
    unsigned int renderer_id;

  public:
    VertexArray();
    ~VertexArray();

    void add_buffer(const VertexBuffer &vertex_buffer,
                    const VertexBufferLayout &layout);
    void bind();
    void unbind();
};
