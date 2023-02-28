#ifndef TP1_RAYTRACING_CAMERA_HH
#define TP1_RAYTRACING_CAMERA_HH

#include "Vector3.hh"

class Camera {
    Point3 center;
    Point3 spottedPoint;
    Vector3 skyDirection;

    float fovAlphaAngle;
    float fovBetaAngle;
    Vector3 fovAlphaDirection;
    Vector3 fovBetaDirection;

    float z_min;

    Camera(){}
    Camera(Point3 center, Point3 spottedPoint, Vector3 skyDirection, float fovAlphaAngle,
           float fovBetaAngle, Vector3 fovAlphaDirection, Vector3 fovBetaDirection, float z_min){
        this->center = center;
        this->spottedPoint = spottedPoint;
        this-> skyDirection = skyDirection;
        this->fovAlphaAngle = fovAlphaAngle;
        this->fovBetaAngle = fovBetaAngle;
        this->fovAlphaDirection = fovAlphaDirection;
        this->fovBetaDirection = fovBetaDirection;
        this->z_min = z_min;
    }

};


#endif //TP1_RAYTRACING_CAMERA_HH
