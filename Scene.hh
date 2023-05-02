#ifndef TP1_RAYTRACING_SCENE_HH
#define TP1_RAYTRACING_SCENE_HH

#include "Camera.hh"
#include "Object.hh"
#include "Light.hh"
#include "Triangle.hh"
#include "Texture_Material.hh"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

class Scene {
public:
    Camera camera;
    std::vector<Object*> objects;
    std::vector<Light*> lights;

    Scene(){}
    Scene(Camera camera){this->camera = camera;}
    Scene(std::vector<Object*> objects){ this->objects = objects;}
    Scene(std::vector<Object*> objects, std::vector<Light*> lights){this->objects = objects;this->lights = lights;}
    Scene(Camera camera, std::vector<Object*> objects, std::vector<Light*> lights){
        this->camera = camera;
        this->objects = objects;
        this->lights = lights;
    }

    void buildSceneFromObjFile(const std::string& filename, Texture_Material* textureMaterial){
        std::ifstream objFile(filename); // replace with your obj file name
        std::vector<Point3> vertices;

        std::string line;
        while (std::getline(objFile, line)) {
            if (line.substr(0, 2) == "v ") {
                std::istringstream s(line.substr(2));
                float x, y, z;
                s >> x >> y >> z;
                vertices.emplace_back(x, y, z);
            }
            else if (line.substr(0, 2) == "f ") {
                std::istringstream s(line.substr(2));
                int v1, v2, v3;
                s >> v1 >> v2 >> v3;
                Triangle* t = new Triangle(textureMaterial, vertices[v1-1], vertices[v2-1], vertices[v3-1]);
                objects.push_back(t);
            }
        }

        // print vertices and triangles
        for (const auto& vertex : vertices) {
            std::cout << "v " << vertex.x << " " << vertex.y << " " << vertex.z << std::endl;
        }
        for (const auto& triangle : objects) {
            triangle->debug();
        }

    }

};


#endif //TP1_RAYTRACING_SCENE_HH
