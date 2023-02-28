#ifndef TP1_RAYTRACING_TEXTURE_MATERIAL_HH
#define TP1_RAYTRACING_TEXTURE_MATERIAL_HH

#include <vector>
#include "Vector3.hh"

class Texture_Material {
public:
    float  kd;
    float ks;
    Color color;

    Texture_Material(){
        this->kd = 0.5;
        this->ks = 0.5;
    }

    virtual std::pair<Color, std::vector<float>> response(Point3 point) = 0;
};


#endif //TP1_RAYTRACING_TEXTURE_MATERIAL_HH
