#pragma once
#include <glad/glad.h>
#include <vector>

class IndexBuffer {
private:
	unsigned int rendererID;
	unsigned int count;

public:
	IndexBuffer(const unsigned int* data, unsigned int size);
	~IndexBuffer();

	void bind() const;
	void unbind() const;

	inline unsigned int getCount() const { return count; }
};
