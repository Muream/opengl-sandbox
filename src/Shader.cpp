#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include "Shader.h"


Shader::Shader(const std::string &filePath) : filePath(filePath), rendererID(0) {
    ShaderProgramSource src = parseShader();
    rendererID = createShader(src.VertexSource, src.FragmentSource);
}
Shader::~Shader() { glDeleteProgram(rendererID); }
void Shader::bind() { glUseProgram(rendererID); }
void Shader::unbind() { glUseProgram(0); }
void Shader::setUniform2f(const std::string &name, float v0, float v1) {
    glUniform2f(getUniformLocation(name), v0, v1);
}
void Shader::setUniform3f(const std::string &name, float v0, float v1, float v2) {
    glUniform3f(getUniformLocation(name), v0, v1, v2);
}
void Shader::setUniform4f(const std::string &name, float v0, float v1, float v2,
                          float v3) {
    glUniform4f(getUniformLocation(name), v0, v1, v2, v3);
}

void Shader::setUniformMat4(const std::string &name, const glm::mat4 &matrix) {
    glUniformMatrix4fv(getUniformLocation(name), 1, GL_FALSE, &matrix[0][0]);
}

ShaderProgramSource Shader::parseShader() {
    std::ifstream stream(filePath);

    enum class ShaderType {
        NONE = -1,
        VERTEX = 0,
        FRAGMENT = 1

    };

    std::string line;
    std::stringstream ss[2];
    ShaderType type = ShaderType::NONE;
    while (getline(stream, line)) {
        if (line.find("#shader") != std::string::npos) {
            if (line.find("vertex") != std::string::npos)
                type = ShaderType::VERTEX;
            else if (line.find("fragment") != std::string::npos)
                type = ShaderType::FRAGMENT;
        } else {
            ss[(int)type] << line << "\n";
        }
    }
    return {ss[0].str(), ss[1].str()};
}
unsigned int Shader::compileShader(int type, const std::string &source) {
    unsigned int id = glCreateShader(type);
    const char *src = source.c_str();

    glShaderSource(id, 1, &src, nullptr);
    glCompileShader(id);

    int result;
    glGetShaderiv(id, GL_COMPILE_STATUS, &result);
    if (result == GL_FALSE) {
        int length;
        glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);

        char *message = (char *)alloca(length * sizeof(char));
        glGetShaderInfoLog(id, length, &length, message);

        std::cout << "Failed to compile"
                  << (type == GL_VERTEX_SHADER ? "vertex" : "fragment") << "shader."
                  << std::endl;
        std::cout << message << std::endl;

        glDeleteShader(id);

        return 0;
    }

    return id;
}
int Shader::createShader(const std::string &vertexShaderSource,
                         const std::string &fragmentShaderSource) {
    unsigned int shaderProgram = glCreateProgram();

    unsigned int vertexShader = compileShader(GL_VERTEX_SHADER, vertexShaderSource);
    glAttachShader(shaderProgram, vertexShader);

    unsigned int fragmentShader =
        compileShader(GL_FRAGMENT_SHADER, fragmentShaderSource);
    glAttachShader(shaderProgram, fragmentShader);

    glLinkProgram(shaderProgram);

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    return shaderProgram;
}

int Shader::getUniformLocation(const std::string &name) {
    return glGetUniformLocation(rendererID, name.c_str());
}
void Shader::checkCompileErrors(unsigned int shader, std::string type) {}
