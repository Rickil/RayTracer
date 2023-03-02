#ifndef TP1_RAYTRACING_VECTOR3_HH
#define TP1_RAYTRACING_VECTOR3_HH
#define PI           3.14159265358979323846

#include <iostream>
#include <string>
#include <cmath>
#include "Point3.hh"
class Vector3 {
public:
    float x;
    float y;
    float z;

    Point3 origin;

    Vector3(){
        this->x = 1;
        this->y = 1;
        this->z = 1;
    }

    Vector3(float x, float y, float z){
        this->x = x;
        this->y = y;
        this->z = z;
    }

    Vector3(Point3 origin, float x, float y, float z){
        this->x = x;
        this->y = y;
        this->z = z;
        this->origin = origin;
    }

    Vector3(Point3 destination, Point3 origin){
        this->x = destination.x - origin.x;
        this->y = destination.y - origin.y;
        this->z = destination.z - origin.z;
        this->origin = origin;
    }

    Point3 getPointReached(){
        return Point3(this->origin.x + this->x, this->origin.y + this->y, this->origin.z + this->z);
    }

    Vector3 rotateY(float angle){
        angle = angle * (PI / 180);
        return Vector3(this->origin, this->x*std::cos(angle)+this->z*std::sin(angle), this->y, this->z*std::cos(angle)-this->x*std::sin(angle));
    }

    Vector3 rotateX(float angle){
        angle = angle * (PI / 180);
        return Vector3(this->origin,this->x, this->y*std::cos(angle)-this->z* std::sin(angle), this->y*std::sin(angle)+this->z*std::cos(angle));
    }

    float magnitude(){
        return std::sqrt(this->x*this->x+this->y*this->y+this->z*this->z);
    }

    Vector3 operator*(const float &l) const{
        return Vector3(this->x * l, this->y * l, this->z*l);
    };
    Vector3 operator+(const float &l) const{
        return Vector3(this->x + l, this->y + l, this->z+l);
    };
    Vector3 operator-(const float &l) const{
        return Vector3(this->x - l, this->y - l, this->z-l);
    };
    Vector3 operator/(const float &l) const{
        return Vector3(this->x / l, this->y / l, this->z/l);
    };
    float operator*(const Vector3 &V) const{
        return this->x * V.x + this->y * V.y +this->z * V.z;
    };
    Vector3 operator+(const Vector3 &V) const{
        return Vector3(this->x + V.x, this->y + V.y, this->z + V.z);
    };
    Vector3 operator-(const Vector3 &V) const{
        return Vector3(this->x - V.x, this->y - V.y, this->z - V.z);
    };

    float operator*(const Point3 &P) const{
        return this->x * P.x + this->y * P.y +this->z * P.z;
    };
    Point3 operator+(const Point3 &P) const{
        return Point3(this->x + P.x, this->y + P.y, this->z + P.z);
    };
    Point3 operator-(const Point3 &P) const{
        return Point3(this->x - P.x, this->y - P.y, this->z - P.z);
    };

};

Vector3 operator-(const Point3 &P1, const Point3 &P2){
    return Vector3(P1, P2);
};

std::ostream& operator<<(std::ostream& out, const Vector3& vector3){
    return out << "(" << std::to_string(vector3.x)  << "," << std::to_string(vector3.y)
               << "," << std::to_string(vector3.z) << ")";
}

#endif //TP1_RAYTRACING_VECTOR3_HH
