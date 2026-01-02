/*
* This file contains all necessary headers for utilizing a bitmap (.bmp)
* Source: https://solarianprogrammer.com/2018/11/19/cpp-reading-writing-bmp-images/
* We usually divide bmp in 4 parts
* file header, bitmap header, color header and pixel data 
*/
#pragma once
#include <cstdint>
#include <vector>
#include <fstream>
#include <stdexcept>

constexpr uint16_t BITMAP_FILETYPE = 0x4D42;

#pragma pack(push, 1) // ensures that no padding happens (BMP needs a multiple of WORD to work)
struct BMPFileHeader{
    uint16_t fileType {BITMAP_FILETYPE};
    uint32_t fileSize {0};
    uint16_t reserved1 {0};
    uint16_t reserved2 {0};
    uint32_t offsetData {0}; // pos in bytes from start of file where pixel starts
};

struct BMPInfoHeader{
    uint32_t size {0};
    int32_t width {0};
    int32_t height {0};

    uint16_t planes {1}; // num of planes for the target device, always 1
    uint16_t bitCount {0}; // bits per pixel
    uint32_t compression {0}; // 0 or 3, umcompressed or not
    uint32_t sizeImage {0}; // 0 fur umcompressed images
    int32_t xPixelsPerMeter{ 0 };
    int32_t yPixelsPerMeter{ 0 };
    uint32_t colors_used{ 0 }; // Num  color indexes in the color table. Use 0 for the max number of colors allowed by bit_count
    uint32_t colors_important{ 0 }; // Num of colors used for displaying the bitmap. If 0 all colors are required
};

// BMP uses BGRA and LITTLE-ENDIAN pattern
struct BMPColorHeader {
    uint32_t redMask{ 0x00ff0000 };         // red channel
    uint32_t greenMask{ 0x0000ff00 };       // green channel
    uint32_t blueMask{ 0x000000ff };        // blue channel
    uint32_t alphaMask{ 0xff000000 };       // alpha channel
    uint32_t color_space_type{ 0x73524742 }; // Default "sRGB" (0x73524742)
    uint32_t unused[16]{ 0 };            // Unused data for sRGB color space
};

#pragma pack(pop) // resets configuration for padding  

struct BMP{
    BMPFileHeader fileHeader;
    BMPInfoHeader infoHeader;
    BMPColorHeader colorHeader; 
    std::vector<uint8_t> data;
    bool isValidFile = true; 

    // Constructor
    BMP(const char *bmpFile){
        read(bmpFile);
    }

    // We will read a bmp, create another instance, modify it and write in another file
    // in this project.
    void read(const char* bmpFile)
    {
        std::ifstream istream(bmpFile, std::ios::binary);
        if (!istream.is_open()){
            throw std::runtime_error("Unable to open this file");
        }
        else{
            istream.read(reinterpret_cast<char *>(&fileHeader), sizeof(fileHeader));
            if (fileHeader.fileType != BITMAP_FILETYPE){
                throw std::runtime_error("Unable to read this file: not in a recognizable format.");
            }
            // now cursor is in infoHeader
            istream.read(reinterpret_cast<char *>(&infoHeader), sizeof(infoHeader));
            // populating our array with the size of bitmap
            data.resize(infoHeader.width * infoHeader.height);

        }
    }
    void modify(const char* bmpFile);
    void write(const char* bmpFile);

};
