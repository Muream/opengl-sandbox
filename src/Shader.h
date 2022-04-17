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

    ShaderProgramSource parse_shader();
    unsigned int compile_shader(int type, const std::string &source);
    int create_shader(const std::string &vertex_shader_source,
                      const std::string &fragment_shader_source);
    int get_uniform_location(const std::string &vertex_shader_source);
    void check_compile_errors(unsigned int shader, std::string type);

  public:
    Shader(const std::string &filepath);
    ~Shader();

    void bind() const;
    void unbind() const;

    void set_uniform_2f(const std::string &name, float v0, float v1);
    void set_uniform_3f(const std::string &name, float v0, float v1, float v2);
    void set_uniform_4f(const std::string &name, float v0, float v1, float v2,
                        float v3);
    void set_uniform_mat4(const std::string &name, const glm::mat4 &matrix);
};
