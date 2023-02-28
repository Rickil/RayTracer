#ifndef TP1_RAYTRACING_SCENE_HH
#define TP1_RAYTRACING_SCENE_HH

#include "Camera.hh"
#include "Object.hh"
#include "Light.hh"

class Scene {
public:
    Camera camera;
    std::vector<Object> objects;
    std::vector<Light> lights;

    Scene(){}
    Scene(Camera camera){this->camera = camera;}
    Scene(std::vector<Object> objects){ this->objects = objects;}
    Scene(std::vector<Object> objects, std::vector<Light> lights){this->objects = objects;this->lights = lights;}
    Scene(Camera camera, std::vector<Object> objects, std::vector<Light> lights){
        this->camera = camera;
        this->objects = objects;
        this->lights = lights;
    }

};


#endif //TP1_RAYTRACING_SCENE_HH
