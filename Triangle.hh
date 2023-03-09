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
        //we get vector from camera center to triangle edges
        Vector3 OA(a, ray.origin);
        Vector3 OB(b, ray.origin);
        Vector3 OC(c, ray.origin);

        //we find the coeffs alpha, beta and gamma
        float alpha = 0;
        float beta = 0;
        float gamma = 0;

        if ((alpha >= 0 && beta >=0 && gamma >= 0) ||(alpha <= 0 && beta <=0 && gamma <= 0)) {
            //we get intersection
            Vector3 OG = (OA * alpha + OB * beta + OC * gamma) / (alpha + beta + gamma);
            //std::cout << OG;
            return OG.setOrigin(ray.origin).getPointReached();
        } else {
            //no intersection
            return std::nullopt;
        }
    }

    Vector3 getNormal(Point3 point){
        //we define the two vectors of the sides
        Vector3 AB(b, a);
        Vector3 AC(c, a);

        return normalize(vectorialProduct(AB, AC)).setOrigin(point);
    }

    std::pair<Color, std::vector<float>> getTexture(Point3 point){
        return this->textureMaterial->response(point);
    }
};


#endif //TP1_RAYTRACING_TRIANGLE_HH
