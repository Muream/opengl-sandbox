#include "VertexArray.h"

VertexArray::VertexArray() { glGenVertexArrays(1, &rendererID); }

VertexArray::~VertexArray() { glDeleteVertexArrays(1, &rendererID); }

void VertexArray::addBuffer(const VertexBuffer &vertexBuffer,
                            const VertexBufferLayout &layout) {
    bind();
    vertexBuffer.bind();

    const auto &elements = layout.getElements();
    unsigned int offset = 0;

    for (unsigned int i = 0; i < elements.size(); i++) {
        const auto &element = elements[i];
        glEnableVertexAttribArray(i);
        glVertexAttribPointer(i, element.count, element.type, element.normalized,
                              layout.getStride(), (void *)offset);

        offset += element.count * VertexBufferElement::getSizeOfType(element.type);
    }
}

void VertexArray::bind() { glBindVertexArray(rendererID); }

void VertexArray::unbind() { glBindVertexArray(0); }
