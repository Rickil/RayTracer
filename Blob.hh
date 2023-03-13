//
// Created by farha on 11/03/2023.
//

#ifndef TP1_RAYTRACING_BLOB_HH
#define TP1_RAYTRACING_BLOB_HH
#define e 0.5
#define d 0.0001

#include "PotentialPoint.hh"
#include <vector>

class Blob {
public:
    std::vector<PotentialPoint> potentialPoints;

    Blob();

    Blob(const std::vector<PotentialPoint> &potentialPoints) : potentialPoints(potentialPoints) {}

    void addPotentialPoints(PotentialPoint potentialPoint){potentialPoints.push_back(potentialPoint);}

    void addPotentialPoints(std::vector<PotentialPoint> potentialPoints){
        this->potentialPoints.insert(this->potentialPoints.end(),
                                     potentialPoints.begin(), potentialPoints.end());
    }
};


#endif //TP1_RAYTRACING_BLOB_HH
