//
// Created by farha on 27/02/2023.
//

#ifndef TP1_RAYTRACING_TOOLS_HH
#define TP1_RAYTRACING_TOOLS_HH
#define PI           3.14159265358979323846


#include "Vector3.hh"
#include <iostream>
#include <cmath>

float square(float number){
    return number*number;
}

float dist(Point3 P1, Point3 P2){
    return std::sqrt(square(P1.x-P2.x) + square(P1.y-P2.y) + square(P1.z-P2.z));
}

float norm(Vector3 V){
    return V*V;
}

Vector3 vectorialProduct(Vector3 u, Vector3 v){
    return Vector3(u.y*v.z-u.z*v.y, u.z*v.x-u.x*v.z, u.x*v.y-u.y*v.x);
}

Vector3 normalize(Vector3 v){
    return (v / v.magnitude()).setOrigin(v.origin);
}

float getAngle(Vector3 u, Vector3 v){
    return std::acos((u*v)/(u.magnitude()*v.magnitude()));
}

#endif //TP1_RAYTRACING_TOOLS_HH
