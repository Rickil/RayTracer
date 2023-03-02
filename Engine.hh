#ifndef TP1_RAYTRACING_ENGINE_HH
#define TP1_RAYTRACING_ENGINE_HH

#include "Scene.hh"
#include "Image.hh"
#include "Vector3.hh"
#include <vector>
#include <utility>

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
            std::optional<Point3> collision = scene.objects[i].intersect(Ray);
            if (collision != std::nullopt) {
                collisions.push_back(std::make_pair(collision.value(), i));
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
            if (distance < newDistance)
                nearestCollision =  collisions[i];
        }

        //get texture infos of collision point
        std::pair<Color, std::vector<float>> textureInfos = this->scene.objects[std::get<int>(nearestCollision)]
                .getTexture(std::get<Point3>(nearestCollision));

        Color color = std::get<Color>(textureInfos);
        float kd = std::get<std::vector<float>>(textureInfos)[0];
        float ks = std::get<std::vector<float>>(textureInfos)[1];

        //apply calculus on color with infos

        //return final pixel color
        return color;
    }

    Image generateImage(){
        Image image(width, height);
        for (int i = 0; i < height; i++){
            float betaAngle = this->scene.camera.fovBetaAngle/(height-1);
            for (int j = 0; j < width; j++){
                float alphaAngle = this->scene.camera.fovAlphaAngle/(width-1);
                Vector3 ref = this->scene.camera.buildImagePlan()[0];
                image.pixels[i][j] = castRay(ref.rotateX(betaAngle).rotateY(alphaAngle));
            }
        }
        return image;
    }
};


#endif //TP1_RAYTRACING_ENGINE_HH
