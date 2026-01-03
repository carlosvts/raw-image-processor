# Raw BMP Image Processor in C++

![C++](https://img.shields.io/badge/c++-%2300599C.svg?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![Linux](https://img.shields.io/badge/Linux-FCC624?style=for-the-badge&logo=linux&logoColor=black)
![Graphics](https://img.shields.io/badge/Graphics-Image--Processing-orange)

## Gallery

| Original | Sobel Edge Detection | Gaussian Blur (15x) |
| :---: | :---: | :---: |
| <img src="assets/lena_color.bmp" width="200"> | <img src="assets/sobelLena.bmp" width="200"> | <img src="assets/lenaBlur.bmp" width="200"> |

| Sepia Tone | Grayscale | Negative |
| :---: | :---: | :---: |
| <img src="assets/sepiaLena.bmp" width="200"> | <img src="assets/grayLena.bmp" width="200"> | <img src="assets/negativeLena.bmp" width="200"> |

---

A low-level image processing engine developed in C++. This project explores binary file manipulation, the internal structure of the BMP (Bitmap) format, and the implementation of mathematical kernels for computer vision.

## About the Project

This project implements a processor capable of reading, modifying, and writing BMP files from scratch without external libraries. It handles the raw byte stream of the image, managing headers, pixel padding, and color channels (BGR/BGRA) manually.

**Main Objectives:**
* Understand the binary structure of BMP headers (`BITMAPFILEHEADER` and `BITMAPINFOHEADER`).
* Manually manage memory buffers using `std::vector<uint8_t>` to store and manipulate raw pixel data.
* Implement spatial filters using **Convolution Kernels** (Gaussian Blur and Sobel Edge Detection).
* Handle alignment and padding requirements (4-byte boundary) for BMP file integrity.

The architecture uses a `BMP` class to encapsulate the file data, providing a clean interface to apply multiple artistic and technical filters.

## Technologies

* **Language:** ISO C++17
* **Compiler:** g++

## How to Build and Run

### Prerequisites

Ensure you have a C++ compiler installed (g++ or clang). This project is cross-platform but was tested primarily in Unix-like environments.

#### Linux Dependencies (Debian/Ubuntu)
```bash
sudo apt-get install g++
```
