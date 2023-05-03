//
// Created by yanis on 5/3/23.
//

#ifndef TP1_RAYTRACING_SDF_HH
#define TP1_RAYTRACING_SDF_HH

#include "Object.hh"

class SDF {
public:
    float dist;
    Point3 intersectionPoint;
    Object* intersectedObject;
    Vector3 ray;

    SDF(float dist, const Point3 &intersectionPoint, Object *intersectedObject, Vector3 ray) : dist(dist),
                                                                                    ray(ray),
                                                                                  intersectionPoint(intersectionPoint),
                                                                                  intersectedObject(
                                                                                          intersectedObject) {}

};


#endif //TP1_RAYTRACING_SDF_HH
