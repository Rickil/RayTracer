#include "Image.hh"
#include <string>
#include <fstream>

void Image::savePPM(std::string path) {
    std::string content = "P3\n";
    content += std::to_string(this->width) + " " + std::to_string(this->height) + "\n";
    content += "255\n";

    std::string line = "";
    for (int i = 0; i < this->width; i++){
        if (i > 0) {
            content += line + "\n";
            line = "";
        }
        for (int j = 0; j < this->height; j++){
            line += std::to_string(this->pixels[i][j].red) + " " + std::to_string(this->pixels[i][j].green)
                    + " " + std::to_string(this->pixels[i][j].blue) + "  ";
            if (content.length() + line.length() + 1 >= 70){
                content += "\n";
            }
        }
    }
    content += line;

    //std::cout << content;
    std::ofstream myfile;
    myfile.open (path);
    myfile << content;
    myfile.close();
}