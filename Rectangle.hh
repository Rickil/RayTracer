//
// Created by root on 04/03/23.
//

#ifndef TP1_RAYTRACING_RECTANGLE_HH
#define TP1_RAYTRACING_RECTANGLE_HH

#include "Object.hh"
#include "Point3.hh"
#include "tools.hh"
#include <iostream>

class Rectangle : public Object{
public:
    Point3 origin;
    Vector3 width;
    Vector3 height;
    Vector3 normal;

    Rectangle(Texture_Material* textureMaterial, Point3 origin, Vector3 width, Vector3 height){
        this->textureMaterial = textureMaterial;
        this->origin = origin;
        this->width = width;
        this->height = height;
        this->normal = normalize(vectorialProduct(width, height));
    }

    std::optional<Point3> intersect(Vector3 ray){
        if (normalize(ray)*normal < 0) {
            return std::nullopt;
        }

        //intersection point P = ray.origin + a*Normalize(Ray)
        //we need to find a
        float a = ((origin-ray.origin)*normal)/(normalize(ray)*normal);
        Point3 intersectionPoint = (normalize(ray)*a).setOrigin(ray.origin).getPointReached();
        //std::cout << "(" << intersectionPoint.x << "," << intersectionPoint.y << "," << intersectionPoint.z << ") ";

        //we check if the point is in the rectangle
        Vector3 Q1 = width*((Vector3(intersectionPoint, origin)*width)/
                (norm(width)));
        Vector3 Q2 = width*((Vector3(intersectionPoint, origin)*height)/
                     (norm(height)));

        if (0 <= Q1.magnitude() && Q1.magnitude() <= width.magnitude()
        && 0 <= Q2.magnitude() && Q2.magnitude() <= height.magnitude()){
            return intersectionPoint;
        }

        return std::nullopt;
    }

    Vector3 getNormal(Point3 point){
        return normal.setOrigin(point);
    }

    std::pair<Color, std::vector<float>> getTexture(Point3 point){
        return this->textureMaterial->response(point);
    }
};


#endif //TP1_RAYTRACING_RECTANGLE_HH
