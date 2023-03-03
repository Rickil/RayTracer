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
        this->red = red;
        this->green = green;
        this->blue = blue;
    }

    Color operator*(const float &l) const{
        return Color(red * l, green*l, blue*l);
    };

};

/*std::ostream& operator<<(std::ostream& out, const Color& color) {
    return out << "(" << std::to_string(color.red) << "," << std::to_string(color.green)
               << "," << std::to_string(color.blue) << ")";
}*/


#endif //TP1_RAYTRACING_COLOR_HH
