#include "scene.h"

Scene::Scene() {}

Scene::~Scene() {}

void Scene::add_mesh(Mesh mesh) { meshes.push_back(mesh); }

std::vector<Mesh> &Scene::get_meshes() { return meshes; }

