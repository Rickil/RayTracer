#include "Uniform_Texture.hh"
#include "Color.hh"
#include "Sphere.hh"


int main(){
    /*std::vector<std::vector<Color>> pixels = {{Color(58, 89, 62),Color(58,230,180)},
                                                {Color(220,186,123), Color(208,123,182)}};
    Image image(2,2,pixels);
    image.savePPM();*/

    Uniform_Texture* uniformTexture = new Uniform_Texture(Color(127,35,203), 0.8, 0.5);
    Sphere sphere(uniformTexture, Point3(5,5,5), 15);
}