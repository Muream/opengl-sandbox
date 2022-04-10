#pragma once
#include <glad/glad.h>

#include "IndexBuffer.h"
#include "Shader.h"
#include "VertexArray.h"


class Renderer {
private:
public:
	void clear(float r, float g, float b) const;
	void draw(
		VertexArray& va,
		IndexBuffer& ib,
		Shader& shader,
		int drawType = GL_TRIANGLES) const;
};
