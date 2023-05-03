#ifndef TP1_RAYTRACING_SPHERE_HH
#define TP1_RAYTRACING_SPHERE_HH

#include "Object.hh"
#include "tools.hh"

class Sphere : public Object{

public:
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
        Vector3 normalizedRay = normalize(ray);
        float det = square(normalizedRay*(ray.origin - this->position))
                -(norm(ray.origin - this->position) - square(this->size));
        if (det < 0)
            return std::nullopt;
        else if (det == 0){
            float res = normalizedRay*(ray.origin - this->position)*-1.0;
            if (res > 0)
                return (normalizedRay*res).setOrigin(ray.origin).getPointReached();
            else
                return std::nullopt;
        }else{
            float res1 = (normalizedRay*(ray.origin - this->position))*-1.0 + std::sqrt(det);
            float res2 = (normalizedRay*(ray.origin - this->position))*-1.0 - std::sqrt(det);

            if (res1 <= 0 && res2 <= 0)
                return std::nullopt;

            Point3 point1 = (normalizedRay*res1).setOrigin(ray.origin).getPointReached();
            Point3 point2 = (normalizedRay*res2).setOrigin(ray.origin).getPointReached();

            return (Vector3(point1, ray.origin).magnitude()
            < Vector3(point2, ray.origin).magnitude()) ? point1 : point2;
        }
    }

    Vector3 getNormal(Point3 point){

        //we get the normal direction by taking the vector from center to intersection point
        Vector3 direction(point, position);

        //we return the vector as a unit vector
        return normalize(direction).setOrigin(point);
    }
    std::pair<Color, std::vector<float>> getTexture(Point3 point){
        return this->textureMaterial->response(point);
    }

    void debug(){
        std::cout << "center: " << position << " radius: " << size << std::endl;
    }

};

#endif //TP1_RAYTRACING_SPHERE_HH
