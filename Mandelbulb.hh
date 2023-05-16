#ifndef TP1_RAYTRACING_MANDELBULB_HH
#define TP1_RAYTRACING_MANDELBULB_HH

#define EPSILON 1

#include "Object.hh"
#include "tools.hh"

class Mandelbulb : public Object{
public:
    float epsilon;
    float power;

    Mandelbulb(Texture_Material* textureMaterial, float power, float epsilon) {
        this->epsilon = epsilon;
        this->power = power;
        this->textureMaterial = textureMaterial;
    }

    std::optional<Point3> intersect(Vector3 ray){return std::nullopt;}

    Vector3 getNormal(Point3 p){
        float x = DE(Vector3(p.x+EPSILON,p.y,p.z), power) - DE(Vector3(p.x-EPSILON,p.y,p.z), power);
        float y = DE(Vector3(p.x,p.y+EPSILON,p.z), power) - DE(Vector3(p.x,p.y-EPSILON,p.z), power);
        float z = DE(Vector3(p.x,p.y,p.z+EPSILON), power) - DE(Vector3(p.x,p.y,p.z-EPSILON), power);
        return normalize(Vector3(p,x,y,z));
    }

    std::pair<Color, std::vector<float>> getTexture(Point3 point){
        return this->textureMaterial->response(point);
    }
    void debug(){}
};


#endif //TP1_RAYTRACING_MANDELBULB_HH
