#include "Uniform_Texture.hh"
#include "Color.hh"
#include "Sphere.hh"
#include "Rectangle.hh"
#include "Camera.hh"
#include "Engine.hh"
#include "Point_Light.hh"

int main(){
    Uniform_Texture* uniformTexture = new Uniform_Texture(Color(127,35,203), 1, 0.8);
    Uniform_Texture* uniformTexture2 = new Uniform_Texture(Color(138,152,103), 0.8, 0.8);
    Uniform_Texture* uniformTexture3 = new Uniform_Texture(Color(10,10,188), 0.8, 0.7);
    Uniform_Texture* uniformTextureSky = new Uniform_Texture(Color(20, 20, 65), 0.8, 0.8);
    Sphere* sphere = new Sphere(uniformTexture, Point3(0.5,3,7), 0.5);
    Sphere* sphere2 = new Sphere(uniformTexture2, Point3(-1,3,7), 0.5);
    Sphere* sphere3 = new Sphere(uniformTexture3, Point3(0,4,5), 0.5);
    Rectangle* rectangleBottom = new Rectangle(uniformTextureSky, Point3(-25,0,-25),
                                         Vector3(0,0,50), Vector3(50,0,0));
    Camera camera(Point3(0,10,6), Point3(0,0,6),Vector3(0,0,1)
                  ,70,70);
    Point_Light* pointLight = new Point_Light(0.8, Point3(0,5,5.5));
    Scene scene(camera);
    scene.objects.push_back(sphere);
    scene.objects.push_back(sphere2);
    //scene.objects.push_back(sphere3);
    scene.objects.push_back(rectangleBottom);
    scene.lights.push_back(pointLight);
    Engine engine(scene, 1000, 1000, 1);
    Image image = engine.generateImage();
    image.savePPM("RayTraced.ppm");

    //std::cout<< normalize(Vector3(0.110257,4.429258,4.768524));
}