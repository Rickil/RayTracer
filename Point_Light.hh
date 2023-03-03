//
// Created by farha on 27/02/2023.
//

#ifndef TP1_RAYTRACING_POINT_LIGHT_HH
#define TP1_RAYTRACING_POINT_LIGHT_HH

#include "Light.hh"

class Point_Light : public Light {
public:

    Point_Light(float intensity, Point3 position){
        this->intensity = intensity;
        this->position = position;
    }
};


#endif //TP1_RAYTRACING_POINT_LIGHT_HH
