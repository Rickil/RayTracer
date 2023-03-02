#include "Uniform_Texture.hh"
#include "Color.hh"
#include "Sphere.hh"
#include "Camera.hh"
#include "Engine.hh"

int main(){
    /*std::vector<std::vector<Color>> pixels = {{Color(58, 89, 62),Color(58,230,180)},
                                                {Color(220,186,123), Color(208,123,182)}};
    Image image(2,2,pixels);
    image.savePPM();*/

    Uniform_Texture* uniformTexture = new Uniform_Texture(Color(127,35,203), 0.8, 0.5);
    Sphere sphere(uniformTexture, Point3(5,5,5), 20);
    Camera camera(Point3(0,3,0), Point3(0,3,5),Vector3(0,1,0)
                  ,70,70, Vector3(0,0,1), Vector3(1,0,0), 4);
    Scene scene(camera);
    scene.objects.push_back(sphere);
    Engine engine(scene, 500, 500);
    Image image = engine.generateImage();
    image.savePPM("RayTraced.ppm");
}