#include "bitmap.hpp"
#include <iostream>
#include <cstring>

int main(int argc, char *argv[])
{
    if (argc < 3){
        std::cout << "Usage: " << argv[0] << "<file> <effect>\n";
        std::cout << "effects: gausianblur, grayscale, sepia, negative, threshold, edge";
        return 1;
    }
    
    const char *filters[] = {"gausianblur", "grayscale", "sepia", "negative", "threshold", "edge"};
    const char *imagePath = argv[1];
    BMP originalImage(imagePath);
    BMP newImage = originalImage;
    char *effectOption = argv[2];

    if (strcmp(effectOption, filters[0]) == 0){
        for(int i = 0; i < 15; i++){
            newImage.applyGausianBlur();
        }
        newImage.write("gausianFiltered.bmp");
    }
    else if (strcmp(effectOption, filters[1]) == 0) { newImage.toGrayScale();  newImage.write("grayFiltered.bmp"); }
    else if (strcmp(effectOption, filters[2]) == 0) { newImage.toSepia(); newImage.write("sepiaFiltered.bmp"); }
    else if (strcmp(effectOption, filters[3]) == 0) { newImage.toNegative(); newImage.write("negativeFiltered.bmp"); }
    else if (strcmp(effectOption, filters[4]) == 0) { newImage.toThreshold(); newImage.write("thresholdFiltered.bmp"); }
    else if (strcmp(effectOption, filters[5]) == 0) { newImage.sobelEdgeDetector(); newImage.write("sobelFiltered.bmp"); }
    else { 
        std::cout << "Incorret usage, effects are case-sensitive!" << std::endl;    
        return 1; 
    }
    return 0;
}

