#include "vertex_array.h"

VertexArray::VertexArray() { glGenVertexArrays(1, &renderer_id); }

VertexArray::~VertexArray() { glDeleteVertexArrays(1, &renderer_id); }

void VertexArray::add_buffer(const VertexBuffer &vertex_buffer,
                             const VertexBufferLayout &layout) {
    bind();
    vertex_buffer.bind();

    const auto &elements = layout.get_elements();
    unsigned int offset = 0;

    for (unsigned int i = 0; i < elements.size(); i++) {
        const auto &element = elements[i];
        glEnableVertexAttribArray(i);
        glVertexAttribPointer(i, element.count, element.type, element.normalized,
                              layout.get_stride(), (void *)offset);

        offset += element.count * VertexBufferElement::getSizeOfType(element.type);
    }
}

void VertexArray::bind() { glBindVertexArray(renderer_id); }

void VertexArray::unbind() { glBindVertexArray(0); }
