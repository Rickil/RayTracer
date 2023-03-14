//
// Created by farha on 11/03/2023.
//

#ifndef TP1_RAYTRACING_POTENTIALPOINT_HH
#define TP1_RAYTRACING_POTENTIALPOINT_HH

#include "Point3.hh"
#include "tools.hh"
#include <cmath>

class PotentialPoint{
public:
    Point3 position;
    float potential;

    PotentialPoint(const Point3 &position, float potential) : position(position), potential(potential) {}

    float getPotential(Point3 point){
        float distance = dist(position, point);
        /*if (distance <= 1)
            return 1;
        else
            return std::exp(-distance);*/
        return std::exp(-distance);
    }
};


#endif //TP1_RAYTRACING_POTENTIALPOINT_HH
