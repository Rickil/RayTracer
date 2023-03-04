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
           float fovBetaAngle){
        this->center = center;
        this->spottedPoint = spottedPoint;
        this->skyDirection = skyDirection;
        this->fovAlphaAngle = fovAlphaAngle;
        this->fovBetaAngle = fovBetaAngle;
        this->z_min = Vector3(spottedPoint, center).magnitude();
    }

    std::vector<Vector3> buildImagePlan(){

        //create plan
        Vector3 spottedPointDirection = Vector3(spottedPoint, center);
        Vector3 res = normalize(vectorialProduct( spottedPointDirection, skyDirection))*z_min*std::sin(fovAlphaAngle/2);
        Vector3 left = Vector3(spottedPoint, res.x, res.y, res.z);

        res = normalize(vectorialProduct(spottedPointDirection, left))*z_min*std::sin(fovBetaAngle/2);
        Vector3 up = Vector3(spottedPoint, res.x, res.y, res.z);

        Point3 p1 = (up+left).setOrigin(spottedPoint).getPointReached();
        Vector3 v1 = Vector3(p1, center);
        Vector3 rightDirection = (left*-2).setOrigin(p1);
        Vector3 downDirection = (up*-2).setOrigin(p1);



        return {v1, rightDirection, downDirection};
    }

};


#endif //TP1_RAYTRACING_CAMERA_HH
