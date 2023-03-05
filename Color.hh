//
// Created by farha on 27/02/2023.
//

#ifndef TP1_RAYTRACING_COLOR_HH
#define TP1_RAYTRACING_COLOR_HH

#include <iostream>

class Color {
public:
    int red;
    int green;
    int blue;

    Color(){
        this->red = 0;
        this->green = 0;
        this->blue = 0;
    }

    Color(int red, int green, int blue){
        this->red = (red <= 255) ? red : 255;
        this->green = (green <= 255) ? green : 255;
        this->blue = (blue <= 255) ? blue : 255;
    }

    Color operator*(const float &l) const{
        return Color(red * l, green*l, blue*l);
    };

    Color operator+(const Color& color) const{
        return Color(red + color.red, green+ color.green, blue+ color.blue);
    };

    Color operator+=(const Color& color) const{
        return Color(red + color.red, green+ color.green, blue+ color.blue);
    };

};

/*std::ostream& operator<<(std::ostream& out, const Color& color) {
    return out << "(" << std::to_string(color.red) << "," << std::to_string(color.green)
               << "," << std::to_string(color.blue) << ")";
}*/


#endif //TP1_RAYTRACING_COLOR_HH
