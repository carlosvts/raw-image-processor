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

    pseudoNewImage.toNegative();
    pseudoNewImage.write("negativeLena.bmp");

    pseudoNewImage.toThreshold();
    pseudoNewImage.write("thresholdLena.bmp");

    std::cout << "Testing lena\n";
}

