#ifndef TP1_RAYTRACING_SPHERE_HH
#define TP1_RAYTRACING_SPHERE_HH

#include "Object.hh"
#include "tools.hh"

class Sphere : public Object{

public:
    Point3 position;
    float size;

    Sphere(Texture_Material* textureMaterial, Point3 position, float size) {
        this->textureMaterial = textureMaterial;
        this->position = position;
        this->size = size;
    }

    Sphere(Texture_Material* textureMaterial, float size) {
        this->textureMaterial = textureMaterial;
        this->size = size;
    }

    std::optional<Point3> intersect(Vector3 ray){
        Vector3 normalizedRay = ray/ray.magnitude();
        float det = square(normalizedRay*(ray.origin - this->position))
                -(norm(ray.origin - this->position) - square(this->size));
        if (det < 0)
            return std::nullopt;
        else if (det == 0){
            float res = ray*(ray.origin - this->position);
            return (normalizedRay*res).getPointReached();
        }else{
            float res1 = ray*(ray.origin - this->position) + std::sqrt(det);
            float res2 = ray*(ray.origin - this->position) - std::sqrt(det);
            Point3 point1 = (normalizedRay*res1).getPointReached();
            Point3 point2 = (normalizedRay*res2).getPointReached();

            return (Vector3(point1, ray.origin).magnitude()
            < Vector3(point2, ray.origin).magnitude()) ? point1 : point2;
        }
    }
    Vector3 getNormal(Point3 point){

        //we get the normal direction by taking the vector from center to intersection point
        Vector3 direction(point, this->position);

        //we set the origin of the vector to the intersection point at the surface
        direction.origin = point;

        //we return the vector as a unit vector
        return normalize(direction);
    }
    std::pair<Color, std::vector<float>> getTexture(Point3 point){
        return this->textureMaterial->response(point);
    }

};

#endif //TP1_RAYTRACING_SPHERE_HH
