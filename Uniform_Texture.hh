#ifndef TP1_RAYTRACING_UNIFORM_TEXTURE_HH
#define TP1_RAYTRACING_UNIFORM_TEXTURE_HH

#include "Texture_Material.hh"
#include "Color.hh"
#include <utility>

class Uniform_Texture : public Texture_Material {

public:

    Uniform_Texture(Color color, float ks, float kd){
        this->ks = ks;
        this->kd = kd;
        this->color = color;
    }

    std::pair<Color, std::vector<float>> response(Point3 point){
        return std::make_pair(this->color, std::vector({this->kd, this->ks}));
    }
};


#endif //TP1_RAYTRACING_UNIFORM_TEXTURE_HH
