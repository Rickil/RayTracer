#ifndef TP1_RAYTRACING_IMAGE_HH
#define TP1_RAYTRACING_IMAGE_HH

#include <vector>
#include "Color.hh"

class Image {
public:
    int width;
    int height;
    std::vector<std::vector<Color>> pixels;

    Image(int width, int height, std::vector<std::vector<Color>> pixels){
        this->width = width;
        this->height = height;
        this->pixels = pixels;
    }

    void savePPM();

};


#endif //TP1_RAYTRACING_IMAGE_HH
