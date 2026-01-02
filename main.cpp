#include "bitmap.hpp"
#include <iostream>

int main()
{
    BMP originalImage("lena_color.bmp");
    BMP pseudoNewImage = originalImage;
    
    pseudoNewImage.toGrayScale();
    pseudoNewImage.write("grayLena.bmp");

    pseudoNewImage.toSepia();
    pseudoNewImage.write("sepiaLena.bmp");

    std::cout << "Testing lena\n";
}

