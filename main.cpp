#include "bitmap.hpp"
#include <iostream>

int main()
{
    BMP originalImage("lena_color.bmp");
    BMP pseudoNewImage = originalImage;
    pseudoNewImage.toGrayScale();
    pseudoNewImage.write("newLena.bmp");

    std::cout << "Testing lena\n";
}

