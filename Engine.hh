#ifndef TP1_RAYTRACING_ENGINE_HH
#define TP1_RAYTRACING_ENGINE_HH

#include "Scene.hh"
#include "Image.hh"
#include "Vector3.hh"
#include "Triangle.hh"
#include "SDF.hh"
#include <vector>
#include <utility>
#include <iostream>

class Engine {
public:
    Scene scene;
    int width;
    int height;
    int maxBounce;
    bool debug = true;

    Vector3 axisX = Vector3(1,0,0);
    Vector3 axisY = Vector3(0,1,0);
    Vector3 axisZ = Vector3(0,0,1);


    Engine(Scene scene, int width, int height, int maxBounce){
        this->scene = scene;
        this->width = width;
        this->height = height;
        this->maxBounce = maxBounce;
    }

    Color applyDiffusion(Object* intersectedObject, Point3 intersectionPoint, Vector3 ray){
        Color color;

        std::pair<Color, std::vector<float>> textureInfos = intersectedObject->getTexture(intersectionPoint);
        Color objectColor = std::get<Color>(textureInfos);
        Vector3 N = intersectedObject->getNormal(intersectionPoint);
        if (Vector3(intersectionPoint, scene.camera.center)*N > 0 /*&& intersectedObject->backFaceCurling*/)
            N = N*-1;
        float kd = std::get<std::vector<float>>(textureInfos)[0];
        for (Light* light : scene.lights) {
            Vector3 L = normalize(Vector3(light->position, intersectionPoint));
            if (!checkCollisions(L).empty()) {
                //std::cout << "no light !";
                continue;
            }
            float I = light->intensity;
            float d = Vector3(intersectionPoint, light->position).magnitude();
            color = color + (objectColor * (N*L) * kd * I); //* (1/std::sqrt(d));
            //std::cout <<N.origin << ":" << N << " " << L.origin << ":" << L << " " << (N*L) << "\n";
        }

        return color;
    }

    Color applySpecular(Object* intersectedObject, Vector3 ray, Point3 intersectionPoint){
        Color color;

        std::pair<Color, std::vector<float>> textureInfos = intersectedObject->getTexture(intersectionPoint);
        Color objectColor = std::get<Color>(textureInfos);
        float ks = std::get<std::vector<float>>(textureInfos)[1];
        Vector3 N = intersectedObject->getNormal(intersectionPoint);
        //std::cout << N << "\n";
        if (Vector3(intersectionPoint, scene.camera.center)*N > 0 /*&& intersectedObject->backFaceCurling*/) {
            //std::cout << " wrong direction !";
            N = N * -1;
        }
        Vector3 rotationAxis = vectorialProduct(ray, N);
        float rotationAngle = getAngle(ray, N);
        Vector3 S = N.rotateAxis(rotationAxis, rotationAngle);
        for (Light* light : scene.lights) {
            Vector3 L = normalize(Vector3(light->position, intersectionPoint));
            if (!checkCollisions(L).empty()) {
                continue;
            }
            float I = light->intensity;
            float d = Vector3(intersectionPoint, light->position).magnitude();
            color = color + (objectColor * (S*L) * ks * I); //* (1/std::sqrt(d));
            //std::cout <<N.origin << ":" << N << " " << L.origin << ":" << L << " " << (N*L) << "\n";
        }


        return color;
    }

    Color applyReflexion(Object* intersectedObject, Vector3 ray, Point3 intersectionPoint, int bounce){
        Color color;

        std::pair<Color, std::vector<float>> textureInfos = intersectedObject->getTexture(intersectionPoint);
        float ks = std::get<std::vector<float>>(textureInfos)[1];
        Vector3 N = intersectedObject->getNormal(intersectionPoint);
        if (Vector3(intersectionPoint, scene.camera.center)*N < 0)
            N = N*-1;
        Vector3 rotationAxis = vectorialProduct(ray, N);
        float rotationAngle = getAngle(ray, N);
        Vector3 S = N.rotateAxis(rotationAxis, rotationAngle).setOrigin(intersectionPoint);
        if (debug) {
            /*std::cout << ray << ray.origin << S << intersectionPoint << "\n";*/
            std::cout << ((Triangle*)intersectedObject)->a << ((Triangle*)intersectedObject)->b << ((Triangle*)intersectedObject)->c << "\n";
        }
        //if (bounce >= 1)
        // std::cout << bounce << ": " << intersectionPoint;
        auto res = castRay(S, bounce+1)*ks;
        debug = false;
        return res;
    }

    std::vector<std::pair<Point3, int>> checkCollisions(Vector3 Ray){
        std::vector<std::pair<Point3, int>> collisions;
        for (int i =0; i < scene.objects.size(); i++){
            std::optional<Point3> collision = scene.objects[i]->intersect(Ray);
            if (collision != std::nullopt && dist(Ray.origin, collision.value()) > 0.0001) {
                collisions.push_back(std::make_pair(Point3(collision.value()), i));
            }
        }
        return collisions;
    }

    SDF sdf(Point3 position){
        //std::cout << "1 ";
        float min = 9999999;
        Point3 point;
        Object* intersectedObject;
        for (Object* object : scene.objects){
            std::optional<Point3> intersectionPoint = object->intersect(Vector3(object->position, position));
            float dist = Vector3(intersectionPoint.value(), position).magnitude();
            if (dist < min){
                min = dist;
                intersectedObject = object;
                point = intersectionPoint.value();
            }
        }

        return SDF(min, point,intersectedObject, Vector3(intersectedObject->position, position));
    }

    Color shade(SDF sdf){
        if (sdf.intersectedObject != nullptr) {
            Color color = std::get<0>(sdf.intersectedObject->getTexture(sdf.intersectionPoint));
            /*Color color = applyDiffusion(sdf.intersectedObject, sdf.intersectionPoint, sdf.ray);*/
            //applySpecular(sdf.intersectedObject, sdf.ray, sdf.intersectionPoint);
            return color;
        }
        else
            return Color(255,255,255);
    }

    Color rayMarch(Vector3 ray){
        float dp = 0;
        Vector3 u = normalize(ray);
        Color pxl = Color(0,0,0);
        float dist;
        Object* intersectedObject;
        Point3* intersectedPoint;
        Point3 pos = scene.camera.center;
        float max = 9999.0f;
        for (int i = 0; i < 150; i++) {
            if (fabs(pos.x) > max
                || fabs(pos.y) > max
                || fabs(pos.z) > max)
                break;
            SDF result = sdf(pos);
            dist = result.dist;
            dp += dist;
            if (dp >= ray.magnitude())
                return pxl;
            if (dist < 0.01) {
                if (fabs(dp - ray.magnitude()) < 0.01)
                    return pxl;
                pxl = shade(result);
                break;
            }

            pos = (u * dist) + pos;
        } // end for (i)
        return pxl;
    }

    Color castRay(Vector3 Ray, int bounce){
        std::cout << "3 ";

        //check collisions with all the scene objects
        std::vector<std::pair<Point3, int>> collisions = checkCollisions(Ray);

        //if no collisions then return black color
        if (collisions.empty()){
            //return Color(0,181,226);
            return Color(0,0,0);
        }

        std::pair<Point3, int> nearestCollision = collisions[0];
        //get the nearest collision point
        for (int i = 1; i < collisions.size(); i++){
            float distance = Vector3(std::get<Point3>(nearestCollision), Ray.origin).magnitude();
            float newDistance = Vector3( std::get<Point3>(collisions[i]), Ray.origin).magnitude();
            if (distance > newDistance) {
                nearestCollision = collisions[i];
            }
        }
        //apply calculus on color with infos
        Object* intersectedObject = this->scene.objects[std::get<int>(nearestCollision)];
        Point3 intersectionPoint = std::get<Point3>(nearestCollision);

        //apply diffusion and specular
        Color color = applyDiffusion(intersectedObject, intersectionPoint, Ray)
                      + applySpecular(intersectedObject, Ray, intersectionPoint);

        if (bounce < maxBounce)
            color = color + applyReflexion(intersectedObject, Ray, intersectionPoint, bounce);
        //std::cout << "(" << color.red << "," << color.green << "," << color.blue << ") ";


        /*if (color.red == 0 && color.green == 0 && color.blue == 0)
            std::cout << ((Triangle*)intersectedObject)->a << ((Triangle*)intersectedObject)->b << ((Triangle*)intersectedObject)->c << "\n";*/
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
                if (j == 530 && i == 530)
                    debug = true;
                //image.pixels[i-1][j-1] = castRay(Ray, 1);
                image.pixels[i-1][j-1] = rayMarch(Ray);
            }
        }
        return image;
    }
};


#endif //TP1_RAYTRACING_ENGINE_HH
