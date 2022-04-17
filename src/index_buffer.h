#pragma once
#include <glad/glad.h>
#include <vector>

class IndexBuffer {
  private:
    unsigned int renderer_id;
    unsigned int count;

  public:
    IndexBuffer(std::vector<unsigned int> indices);
    ~IndexBuffer();

    void bind() const;
    void unbind() const;

    inline unsigned int get_count() const { return count; }
};
