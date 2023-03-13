//
// Created by farha on 11/03/2023.
//

#ifndef TP1_RAYTRACING_BLOB_HH
#define TP1_RAYTRACING_BLOB_HH
#define e 50
#define d 0.1
#define isoLevelRequired 1
#define cubeOriginX -25
#define cubeOriginY -25
#define cubeOriginZ -25


#include "PotentialPoint.hh"
#include "Object.hh"
#include "Triangle.hh"
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

    std::vector<Point3> getCube(float x, float y, float z){
        Point3 p1(cubeOriginX+x, cubeOriginY+y, cubeOriginZ+z);
        Point3 p2(cubeOriginX+x+d, cubeOriginY+y, cubeOriginZ+z);
        Point3 p3(cubeOriginX+x, cubeOriginY+y+d, cubeOriginZ+z);
        Point3 p4(cubeOriginX+x, cubeOriginY+y, cubeOriginZ+z+d);
        Point3 p5(cubeOriginX+x+d, cubeOriginY+y, cubeOriginZ+z+d);
        Point3 p6(cubeOriginX+x+d, cubeOriginY+y+d, cubeOriginZ+z);
        Point3 p7(cubeOriginX+x, cubeOriginY+y+d, cubeOriginZ+z+d);
        Point3 p8(cubeOriginX+x+d, cubeOriginY+y+d, cubeOriginZ+z+d);

        return {p1,p2,p3,p4,p5,p6,p7,p8};
    }

    std::vector<Object*> renderBlob(){
        for (int x = 0; x < e-d; x+=d){
            for (int y = 0; y < e-d; y+=d){
                for (int z = 0; z < e-d; z+=d){
                    std::vector<Point3> corners = getCube(x, y , z);
                }
            }
        }
    }
};


#endif //TP1_RAYTRACING_BLOB_HH
