//
// Created by farha on 27/02/2023.
//

#ifndef TP1_RAYTRACING_TOOLS_HH
#define TP1_RAYTRACING_TOOLS_HH


#include "Vector3.hh"
#include <iostream>
#include <cmath>

float square(float number){
    return number*number;
}

float norm(Point3 P){
    return square(P.x) + square(P.y) + square(P.z);
}

float norm(Vector3 V){
    return V*V;
}

#endif //TP1_RAYTRACING_TOOLS_HH
