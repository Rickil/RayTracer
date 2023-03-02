#ifndef TP1_RAYTRACING_CAMERA_HH
#define TP1_RAYTRACING_CAMERA_HH

#include "Vector3.hh"
#include "tools.hh"
#include <vector>

class Camera {
public:
    Point3 center;
    Point3 spottedPoint;
    Vector3 skyDirection;

    float fovAlphaAngle;
    float fovBetaAngle;
    Vector3 fovAlphaDirection;
    Vector3 fovBetaDirection;

    float z_min;

    Vector3 relativeAxisX = Vector3(center, 1,0,0);
    Vector3 relativeAxisY = Vector3(center, 0,1,0);
    Vector3 relativeAxisZ = Vector3(center, 0,0,1);

    Camera(){}
    Camera(Point3 center, Point3 spottedPoint, Vector3 skyDirection, float fovAlphaAngle,
           float fovBetaAngle, float z_min){
        this->center = center;
        this->spottedPoint = spottedPoint;
        this->skyDirection = skyDirection;
        this->fovAlphaAngle = fovAlphaAngle;
        this->fovBetaAngle = fovBetaAngle;
        this->z_min = z_min;
    }

    std::vector<Vector3> buildImagePlan(){

        //create plan
        Vector3 spottedPointDirection = Vector3(spottedPoint, center);
        Vector3 res = normalize(vectorialProduct(skyDirection, spottedPointDirection))*z_min*std::sin(fovAlphaAngle/2);
        Vector3 left = Vector3(spottedPoint, res.x, res.y, res.z);

        res = normalize(vectorialProduct(left, spottedPointDirection))*z_min*std::sin(fovBetaAngle/2);
        Vector3 up = Vector3(spottedPoint, res.x, res.y, res.z);

        Vector3 v1 = 

        return {v1, v2, v3, v4};
    }

};


#endif //TP1_RAYTRACING_CAMERA_HH
