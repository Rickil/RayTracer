#ifndef TP1_RAYTRACING_TRIANGLE_HH
#define TP1_RAYTRACING_TRIANGLE_HH

#include "Object.hh"
#include "tools.hh"
#include <iostream>

class Triangle : public Object{
public:
    Point3 a;
    Point3 b;
    Point3 c;

    Triangle(Texture_Material* textureMaterial1, Point3 a, Point3 b, Point3 c){
        this->textureMaterial = textureMaterial1;
        this->a = a;
        this->b = b;
        this->c = c;
        this->backFaceCurling = true;
    }

    float getCoeffs(Vector3 u, Vector3 v){
        if (u.x != 0 && v.x != 0){
            return u.x / v.x;
        }else if (u.y != 0 && v.y != 0){
            return u.y / v.y;
        }else if (u.z != 0 && v.z != 0){
            return u.z / v.z;
        }
        else{
            return 0;
        }
    }

    std::optional<Point3> intersect(Vector3 ray){
        const float EPSILON = 0.0001;

        //we get vector from camera center to triangle edges
        Vector3 edge1(this->b,this->a);
        Vector3 edge2(this->c,this->a);

        Vector3 h = vectorialProduct(ray, edge2);
        float a = edge1*h;
        if (a > -EPSILON && a < EPSILON)
            return std::nullopt;

        float f = 1.0/a;
        Vector3 s = Vector3(ray.origin, this->a);
        float u = s*h*f;
        if (u < 0.0 || u > 1.0)
            return std::nullopt;

        Vector3 q = vectorialProduct(s, edge1);
        float v = ray*q*f;
        if (v < 0.0 || u + v > 1.0)
            return std::nullopt;

        float t = edge2*q*f;
        if (t > EPSILON){
            return (ray*t).setOrigin(ray.origin).getPointReached();
        }else{
            return std::nullopt;
        }
    }

    Vector3 getNormal(Point3 point){
        //we define the two vectors of the sides
        Vector3 AB(b, a);
        Vector3 AC(c, a);

        return normalize(vectorialProduct(AC, AB)).setOrigin(point);
    }

    std::pair<Color, std::vector<float>> getTexture(Point3 point){
        return this->textureMaterial->response(point);
    }
};


#endif //TP1_RAYTRACING_TRIANGLE_HH
