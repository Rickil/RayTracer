#include "Uniform_Texture.hh"
#include "Color.hh"
#include "Sphere.hh"
#include "Rectangle.hh"
#include "Camera.hh"
#include "Engine.hh"
#include "Point_Light.hh"
#include "Triangle.hh"
#include "Blob.hh"
#include "Sierpinski.hh"

int main(){
    //Uniform_Texture* uniformTexture = new Uniform_Texture(Color(127,35,203), 1, 0.1);
    /*Uniform_Texture* uniformTexture2 = new Uniform_Texture(Color(138,152,103), 1, 0.8);
    Uniform_Texture* uniformTexture3 = new Uniform_Texture(Color(10,10,188), 1, 0.7);
    Uniform_Texture* uniformTexture4 = new Uniform_Texture(Color(210,10,53), 1, 0.8);
    Uniform_Texture* uniformTextureSky = new Uniform_Texture(Color(20, 20, 65), 1, 0.8);
    Sphere* sphere = new Sphere(uniformTexture, Point3(0.5,3,7), 0.5);
    Sphere* sphere2 = new Sphere(uniformTexture2, Point3(-1,3,7), 0.5);
    Sphere* sphere3 = new Sphere(uniformTexture3, Point3(1,4,6), 0.5);
    Sphere* sphere4 = new Sphere(uniformTexture4, Point3(-1,0.5,6), 0.5);
    Rectangle* rectangleBottom = new Rectangle(uniformTextureSky, Point3(-25,0,-25),
                                         Vector3(0,0,50), Vector3(50,0,0));
    Triangle* triangle = new Triangle(uniformTexture, Point3(-1,0,4),
                                      Point3(0,4,5), Point3(1,0,4));*/
    /*Camera camera(Point3(1,20,2), Point3(1,0,2), Vector3(0,0,1)
                  ,70,70);
    Point_Light* pointLight = new Point_Light(0.8, Point3(4.07625 ,10.00545 ,5.90386));
    Scene scene(camera);*/
    //scene.buildSceneFromObjFile("untitled.obj", uniformTexture);
    //#############
    /*for (auto triangle : triangles){
        scene.objects.push_back(triangle);
    }*/
    /*scene.objects.push_back(new Triangle(uniformTexture, Point3(0.250000,2.500000,5.000000), Point3(0.000000,2.500000,5.250000), Point3(0.250000,3.000000,5.500000)));
    scene.lights.push_back(pointLight);
    Engine engine(scene, 1000, 1000, 1);
    Image image = engine.generateImage();
    image.savePPM("RayTraced.ppm");*/

    Sierpinski fractal = Sierpinski(60,2);

    return 0;
}
