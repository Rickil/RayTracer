//
// Created by farha on 11/03/2023.
//

#ifndef TP1_RAYTRACING_BLOB_HH
#define TP1_RAYTRACING_BLOB_HH
#define e 50
#define d 0.1
#define S 1
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
    Texture_Material* textureMaterial;

    Blob();

    Blob(const std::vector<PotentialPoint> &potentialPoints, Texture_Material *textureMaterial1) : potentialPoints(
            potentialPoints), textureMaterial(textureMaterial1) {}

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

    int getIndex(std::vector<Point3> corners){
        int index = 0;
        for (int i = 0; i < corners.size(); i++){
            float potential = 0;
            for (PotentialPoint potentialPoint : potentialPoints){
                potential += potentialPoint.getPotential(corners[i]);
            }
            if (potential < S)
                index |= intPow(2,i);
        }
    }

    Point3 getPointFromVertex(int vertex, Point3 position){
        switch (vertex) {
            case 0:
                return position;
            case 1:
                return position.addX(d);
            case 2:
                return position.addX(d).addZ(d);
            case 3:
                return position.addZ(d);
            case 4:
                return position.addY(d);
            case 5:
                return position.addY(d).addX(d);
            case 6:
                return position.addY(d).addX(d).addZ(d);
            case 7:
                return position.addY(d).addZ(d);
            case 8:
                return position.addY(d/2);
            case 9:
                return position.addX(d).addY(d/2);
            case 10:
                return position.addX(d).addZ(d).addY(d/2);
            case 11:
                return position.addZ(d).addY(d/2);
        }
    }

    void getTriangles(int* vertices, Point3 position, std::vector<Object*>* objects){
        for (int i = 0; i < 15; i+=3){
            if (vertices[i] != -1){
                Point3 a = getPointFromVertex(vertices[i], position);
                Point3 b = getPointFromVertex(vertices[i+1], position);
                Point3 c = getPointFromVertex(vertices[i+2], position);
                objects->push_back(new Triangle(textureMaterial, a, b, c));
            }
        }
    }

    std::vector<Object*> renderBlob(){
        std::vector<Object*> objects;
        for (int x = 0; x < e-d; x+=d){
            for (int y = 0; y < e-d; y+=d){
                for (int z = 0; z < e-d; z+=d){
                    std::vector<Point3> corners = getCube(x, y , z);
                    int index = getIndex(corners);
                    int* vertices = frontiers[index];
                    Point3 position = Point3(cubeOriginX+x, cubeOriginY+y, cubeOriginZ+z);
                    getTriangles(vertices, position, &objects);
                }
            }
        }
        return objects;
    }
};


#endif //TP1_RAYTRACING_BLOB_HH
