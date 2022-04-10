#pragma once
#include <string>

#include "glad/glad.h"
#include "glm/glm.hpp"

struct ShaderProgramSource {
	std::string VertexSource;
	std::string FragmentSource;
};


class Shader {
private:
	unsigned int rendererID;
	std::string filePath;

	ShaderProgramSource parseShader();
	unsigned int compileShader(int type, const std::string& source);
	int createShader(const std::string& vertexShaderSource, const std::string& fragmentShaderSource);
	int getUniformLocation(const std::string& vertexShaderSource);
	void checkCompileErrors(unsigned int shader, std::string type);

public:
	Shader(const std::string& filepath);
	~Shader();
	void bind();
	void unbind();

	void setUniform2f(const std::string& name, float v0, float v1);
	void setUniform3f(const std::string& name, float v0, float v1, float v2);
	void setUniform4f(const std::string& name, float v0, float v1, float v2, float v3);
	void setUniformMat4(const std::string& name, const glm::mat4& matrix);
};
