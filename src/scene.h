#pragma once
#include "mesh.h"
#include <vector>

class Scene {
  public:
    Scene();
    ~Scene();

    void add_mesh(Mesh mesh);

    std::vector<Mesh> &get_meshes();

  private:
    std::vector<Mesh> meshes;
};