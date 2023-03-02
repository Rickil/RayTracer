#ifndef TP1_RAYTRACING_OBJECT_HH
#define TP1_RAYTRACING_OBJECT_HH

#include "Texture_Material.hh"
#include <optional>

class Object {
public:
    Texture_Material* textureMaterial;

    virtual std::optional<Point3> intersect(Vector3 ray){}
    virtual Vector3 getNormal(Point3 point){}
    virtual std::pair<Color, std::vector<float>> getTexture(Point3 point){}

};


#endif //TP1_RAYTRACING_OBJECT_HH
