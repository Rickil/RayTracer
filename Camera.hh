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

    std::vector<Vector3> buildImagePlan(){

        //create plan
        Vector3 v1 = (fovAlphaDirection*z_min);
        Vector3 v2 = v1.rotateX(fovBetaAngle);
        Vector3 v3 = v2.rotateY(fovAlphaAngle);
        Vector3 v4 = v1.rotateY(fovBetaAngle);
        std::cout << v1 << "\n"<< v2 << "\n"<< v3 << "\n"<< v4 << "\n";

        //get X and Y rotation angles of spottedPoint vector
        Vector3 spottedPointDirection = Vector3(spottedPoint, center);
        float angleX = std::acos((relativeAxisX * spottedPointDirection)/
                (relativeAxisX.magnitude()*spottedPointDirection.magnitude()))+fovBetaAngle/2;
        float angleY = std::acos((relativeAxisY * spottedPointDirection)/
                                 (relativeAxisY.magnitude()*spottedPointDirection.magnitude()))+fovAlphaAngle/2;


        //rotate plan to be aligned with spottedPoint
        v1 = v1.rotateX(angleX).rotateY(angleY);
        v2 = v2.rotateX(angleX).rotateY(angleY);
        v3 = v3.rotateX(angleX).rotateY(angleY);
        v4 = v4.rotateX(angleX).rotateY(angleY);

        return {v1, v2, v3, v4};
    }

};


#endif //TP1_RAYTRACING_CAMERA_HH
