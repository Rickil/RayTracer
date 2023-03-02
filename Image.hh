#ifndef TP1_RAYTRACING_IMAGE_HH
#define TP1_RAYTRACING_IMAGE_HH

#include <vector>
#include <string>
#include "Color.hh"

class Image {
public:
    int width;
    int height;
    std::vector<std::vector<Color>> pixels;

    Image(int width, int height){
        this->width = width;
        this->height = height;

        //initialize null sized array for pixels
        this->pixels.resize(height);
        for (int i = 0; i < height; i++){
            this->pixels[i].resize(width);
        }
    }

    Image(int width, int height, std::vector<std::vector<Color>> pixels){
        this->width = width;
        this->height = height;
        this->pixels = pixels;
    }

    void savePPM(std::string path);

};


#endif //TP1_RAYTRACING_IMAGE_HH
