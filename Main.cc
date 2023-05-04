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
#include <string>

int main(){
    Uniform_Texture* uniformTexture = new Uniform_Texture(Color(127,35,203), 0.5, 0.5);
    Uniform_Texture* uniformTexture2 = new Uniform_Texture(Color(138,152,103), 1, 0.8);
    /*Uniform_Texture* uniformTexture3 = new Uniform_Texture(Color(10,10,188), 1, 0.7);
    Uniform_Texture* uniformTexture4 = new Uniform_Texture(Color(210,10,53), 1, 0.8);
    Uniform_Texture* uniformTextureSky = new Uniform_Texture(Color(20, 20, 65), 1, 0.8);*/
    Sphere* sphere = new Sphere(uniformTexture, Point3(0.4,3,0), 0.5);
    Sphere* sphere2 = new Sphere(uniformTexture2, Point3(-0.4,3,0), 0.5);
    /*Sphere* sphere3 = new Sphere(uniformTexture3, Point3(1,4,6), 0.5);
    Sphere* sphere4 = new Sphere(uniformTexture4, Point3(-1,0.5,6), 0.5);
    Rectangle* rectangleBottom = new Rectangle(uniformTextureSky, Point3(-25,0,-25),
                                         Vector3(0,0,50), Vector3(50,0,0));
    Triangle* triangle = new Triangle(uniformTexture, Point3(-1,0,4),
                                      Point3(0,4,5), Point3(1,0,4));*/
    Camera camera(Point3(-2,-2,0.1), Point3(0,0,0.1), Vector3(0,0,1)
                  ,70,70);
    Point_Light* pointLight = new Point_Light(1, Point3(-1 ,-1 ,0));
    /*Point_Light* pointLight2 = new Point_Light(1, Point3(2 ,2 ,0));

    Camera camera2(Point3(0,0,4), Point3(0,0,0.1), Vector3(0,1,0)
            ,70,70);
    Scene scene2(camera2);*/






    Scene scene(camera);
    //scene.buildSceneFromObjFile("untitled.obj", uniformTexture);
    //#############
    /*for (auto triangle : triangles){
        scene.objects.push_back(triangle);
    }*/
    //scene.objects.push_back(new Triangle(uniformTexture, Point3(0.250000,2.500000,5.000000), Point3(0.000000,2.500000,5.250000), Point3(0.250000,3.000000,5.500000)));
    scene.lights.push_back(pointLight);
    //scene2.lights.push_back(pointLight2);
    Engine engine(scene, 1000, 1000, 1);
    //Engine engine2(scene2, 1000, 1000, 1);
    for (float i = 1; i < 9; i+=0.25) {
        Image image = engine.generateImage(i);
        image.savePPM("Mandelbulb" + std::to_string(i) + ".ppm");
        std::cout << "saved " << i << "\n";
    }
    /*image = engine2.generateImage();
    image.savePPM("RayTraced2.ppm");
    std::cout << "saved 2\n";*/

    //Sierpinski fractal = Sierpinski(60,2);

    return 0;
}
