#ifndef TP1_RAYTRACING_OBJECT_HH
#define TP1_RAYTRACING_OBJECT_HH

#include "Texture_Material.hh"
#include <optional>

class Object {
public:
    Texture_Material* textureMaterial;

    virtual std::optional<Point3> intersect(Vector3 ray) = 0;
    virtual Vector3 getNormal(Point3 point) = 0;
    virtual std::vector<float> getTexture(Point3 point) = 0;

};


#endif //TP1_RAYTRACING_OBJECT_HH
