#ifndef TP1_RAYTRACING_ENGINE_HH
#define TP1_RAYTRACING_ENGINE_HH

#include "Scene.hh"
#include "Image.hh"
#include "Vector3.hh"
#include <vector>
#include <utility>
#include <iostream>

class Engine {
public:
    Scene scene;
    int width;
    int height;

    Vector3 axisX = Vector3(1,0,0);
    Vector3 axisY = Vector3(0,1,0);
    Vector3 axisZ = Vector3(0,0,1);


    Engine(Scene scene, int width, int height){
        this->scene = scene;
        this->width = width;
        this->height = height;
    }

    Color castRay(Vector3 Ray){

        //check collisions with all the scene objects
        std::vector<std::pair<Point3, int>> collisions;
        for (int i =0; i < scene.objects.size(); i++){

            std::optional<Point3> collision = scene.objects[i]->intersect(Ray);
            if (collision != std::nullopt) {
                //std::cout << "collision !";
                collisions.push_back(std::make_pair(Point3(collision.value()), i));
            }
        }

        //if no collisions then return black color
        if (collisions.empty()){
            return Color(0,0,0);
        }

        std::pair<Point3, int> nearestCollision = collisions[0];
        //get the nearest collision point
        for (int i = 1; i < collisions.size(); i++){
            float distance = Vector3(std::get<Point3>(nearestCollision), this->scene.camera.center).magnitude();
            float newDistance = Vector3( std::get<Point3>(collisions[i]), this->scene.camera.center).magnitude();
            if (distance > newDistance) {
                nearestCollision = collisions[i];
            }
        }

        //get texture infos of collision point
        Object* intersectedObject = this->scene.objects[std::get<int>(nearestCollision)];
        Point3 intersectionPoint = std::get<Point3>(nearestCollision);
        //std::cout << intersectionPoint;
        std::pair<Color, std::vector<float>> textureInfos = this->scene.objects[std::get<int>(nearestCollision)]
                ->getTexture(std::get<Point3>(nearestCollision));

        Color color = std::get<Color>(textureInfos);
        float kd = std::get<std::vector<float>>(textureInfos)[0];
        float ks = std::get<std::vector<float>>(textureInfos)[1];

        //apply calculus on color with infos

        //apply diffusion

        for (Light* light : scene.lights) {
            Vector3 N = intersectedObject->getNormal(intersectionPoint);
            Vector3 L = normalize(Vector3(light->position, intersectionPoint));
            float I = light->intensity;
            float d = Vector3(intersectionPoint, scene.camera.center).magnitude();
            color = color * (N*L) * kd * I; //* (1/std::sqrt(d));
            std::cout <<N.origin << ":" << N << " " << L.origin << ":" << L << " " << (N*L) << "\n";
        }
        //std::cout << "(" << color.red << "," << color.green << "," << color.blue << ") ";


        //return final pixel color
        return color;
    }

    Image generateImage(){
        Image image(width, height);
        std::vector<Vector3> planInfos = scene.camera.buildImagePlan();
        Vector3 refVector = planInfos[0];
        Vector3 rightDirection = planInfos[1];
        Vector3 downDirection = planInfos[2];
        for (int i = 1; i < height+1; i++){
            Vector3 pixelFinderDown = (downDirection/height*i).setOrigin(refVector.getPointReached());
            for (int j = 1; j < width+1; j++){
                Vector3 pixelFinderRight = (rightDirection/width*j).setOrigin(pixelFinderDown.getPointReached());
                Vector3 Ray = Vector3(pixelFinderRight.getPointReached(), scene.camera.center);
                image.pixels[i-1][j-1] = castRay(Ray);
            }
        }
        return image;
    }
};


#endif //TP1_RAYTRACING_ENGINE_HH
