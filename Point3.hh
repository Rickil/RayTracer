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

    Point3(float x, float y, float z){
        this->x = x;
        this->y = y;
        this->z = z;
    }

};


#endif //TP1_RAYTRACING_POINT3_HH
