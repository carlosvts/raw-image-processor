#include "bitmap.hpp"
#include <iostream>

int main()
{
    BMP originalImage("lena_color.bmp");
    BMP pseudoNewImage = originalImage;
    
    //for(int i = 0; i < 20; i++){
    //    pseudoNewImage.applyGausianBlur();
    //    pseudoNewImage.write("gausianLena.bmp");
    //}

   //pseudoNewImage.toGrayScale();
   //pseudoNewImage.write("grayLena.bmp");

  // pseudoNewImage.toSepia();
  // pseudoNewImage.write("sepiaLena.bmp");

   //pseudoNewImage.toNegative();
   // pseudoNewImage.write("negativeLena.bmp");

   //pseudoNewImage.toThreshold();
   //pseudoNewImage.write("thresholdLena.bmp");

   pseudoNewImage.sobelEdgeDetector();
   pseudoNewImage.write("sobelLena.bmp");

    std::cout << "Testing lena\n";
}

