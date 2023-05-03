//
// Created by farha on 27/02/2023.
//

#ifndef TP1_RAYTRACING_POINT3_HH
#define TP1_RAYTRACING_POINT3_HH

#include "Vector3.hh"

class Point3 {
public:
    float x;
    float y;
    float z;

    Point3(){
        this->x = 0;
        this->y = 0;
        this->z = 0;
    }

    Point3(Point3 const &point){
        this->x = point.x;
        this->y = point.y;
        this->z = point.z;
    }

    Point3(float x, float y, float z){
        this->x = x;
        this->y = y;
        this->z = z;
    }

    Point3 addX(float v){
        return Point3(x+v, y, z);
    }

    Point3 addY(float v){
        return Point3(x, y+v, z);
    }

    Point3 addZ(float v){
        return Point3(x, y, z+v);
    }

    bool operator!=(Point3 point){
        return (x != point.x || y != point.y || z != point.z);
    }

};

std::ostream& operator<<(std::ostream& out, const Point3& point){
    return out << "(" << std::to_string(point.x)  << "," << std::to_string(point.y)
               << "," << std::to_string(point.z) << ")";
}


#endif //TP1_RAYTRACING_POINT3_HH
