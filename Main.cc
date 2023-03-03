#include "Uniform_Texture.hh"
#include "Color.hh"
#include "Sphere.hh"
#include "Camera.hh"
#include "Engine.hh"
#include "Point_Light.hh"

int main(){
    /*std::vector<std::vector<Color>> pixels = {{Color(58, 89, 62),Color(58,230,180)},
                                                {Color(220,186,123), Color(208,123,182)}};
    Image image(2,2,pixels);
    image.savePPM();*/

    Uniform_Texture* uniformTexture = new Uniform_Texture(Color(127,35,203), 0.8, 0.8);
    Uniform_Texture* uniformTexture2 = new Uniform_Texture(Color(138,152,103), 0.8, 0.8);
    Sphere* sphere = new Sphere(uniformTexture, Point3(5,3,5), 1);
    //Sphere* sphere2 = new Sphere(uniformTexture2, Point3(8,3,5), 1);
    Camera camera(Point3(0.5,3,0), Point3(10,3,10),Vector3(0,1,0)
                  ,70,70);
    Point_Light* pointLight = new Point_Light(0.5, Point3(8,3,5));
    Scene scene(camera);
    scene.objects.push_back(sphere);
    //scene.objects.push_back(sphere2);
    scene.lights.push_back(pointLight);
    Engine engine(scene, 1000, 1000);
    Image image = engine.generateImage();

    /*auto plan = camera.buildImagePlan();
    for (int i = 0; i < plan.size(); i++){
        //for (int j = 0; j < image.width; j++){
            //Color color = image.pixels[i][j];
           std::cout << "(" << std::to_string(plan[i].x) << "," << std::to_string(plan[i].y)
                << "," << std::to_string(plan[i].z) << ")";
        //}
    }*/
    image.savePPM("RayTraced.ppm");
    /*Vector3 vector(0,0,4);
    std::cout << vector.rotateX(70);*/
}