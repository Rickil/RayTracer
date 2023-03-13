//
// Created by farha on 11/03/2023.
//

#ifndef TP1_RAYTRACING_POTENTIALPOINT_HH
#define TP1_RAYTRACING_POTENTIALPOINT_HH

class PotentialPoint{
public:
    float x;
    float y;
    float z;
    float potential;

    PotentialPoint(float x, float y, float z, float potential) : x(x), y(y), z(z), potential(potential) {}
};


#endif //TP1_RAYTRACING_POTENTIALPOINT_HH
