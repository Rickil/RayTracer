#ifndef TP1_RAYTRACING_MANDELBULB_HH
#define TP1_RAYTRACING_MANDELBULB_HH

#define EPSILON 0.001

#include "Object.hh"
#include "tools.hh"

class Mandelbulb : public Object{
public:
    float epsilon;

    Mandelbulb(Texture_Material* textureMaterial) {
        this->textureMaterial = textureMaterial;
        this->epsilon = epsilon;
    }

    std::optional<Point3> intersect(Vector3 ray){return std::nullopt;}

    Vector3 getNormal(Point3 p){
        float x = DE(Vector3(p.x+EPSILON,p.y,p.z)) - DE(Vector3(p.x-EPSILON,p.y,p.z));
        float y = DE(Vector3(p.x,p.y+EPSILON,p.z)) - DE(Vector3(p.x,p.y-EPSILON,p.z));
        float z = DE(Vector3(p.x,p.y,p.z+EPSILON)) - DE(Vector3(p.x,p.y,p.z-EPSILON));
        return normalize(Vector3(p,x,y,z));
    }

    std::pair<Color, std::vector<float>> getTexture(Point3 point){
        return this->textureMaterial->response(point);
    }
    void debug(){}
};


#endif //TP1_RAYTRACING_MANDELBULB_HH
