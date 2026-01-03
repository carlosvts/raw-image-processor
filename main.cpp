#include "bitmap.hpp"
#include <iostream>
#include <cstring>

int main(int argc, char *argv[])
{
    if (argc < 3){
        std::cout << "Usage: " << argv[0] << "<file> <effect> <output>\n";
        std::cout << "effects: gausianblur, grayscale, sepia, negative, threshold, edge";
        return 1;
    }
    
    const char *filters[] = {"gausianblur", "grayscale", "sepia", "negative", "threshold", "edge"};
    const char *imagePath = argv[1];
    BMP originalImage(imagePath);
    BMP newImage = originalImage;
    char *effectOption = argv[2];
    const char *outputFileName = argv[3];

    if (strcmp(effectOption, filters[0]) == 0){
        for(int i = 0; i < 15; i++){
            newImage.applyGausianBlur();
        }
        newImage.write(outputFileName);
    }
    else if (strcmp(effectOption, filters[1]) == 0) { newImage.toGrayScale();  newImage.write(outputFileName); }
    else if (strcmp(effectOption, filters[2]) == 0) { newImage.toSepia(); newImage.write(outputFileName); }
    else if (strcmp(effectOption, filters[3]) == 0) { newImage.toNegative(); newImage.write(outputFileName); }
    else if (strcmp(effectOption, filters[4]) == 0) { newImage.toThreshold(); newImage.write(outputFileName); }
    else if (strcmp(effectOption, filters[5]) == 0) { newImage.sobelEdgeDetector(); newImage.write(outputFileName); }
    else { 
        std::cout << "Incorret usage, effects are case-sensitive!" << std::endl;    
        return 1; 
    }
    return 0;
}

