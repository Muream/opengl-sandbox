#pragma once
#include <glad/glad.h>
#include <vector>

#include "vertex.h"

class VertexBuffer {
private:
	unsigned int renderer_id;

public:
	VertexBuffer(std::vector<Vertex>);
	~VertexBuffer();

	void bind() const;
	void unbind() const;
};
