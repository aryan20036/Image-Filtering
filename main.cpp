// main.cpp

#include <iostream>
#include <string>
#include <cuda_runtime.h>
#include "image_filtering.h"

int main(int argc, char** argv) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " input_image output_image" << std::endl;
        return 1;
    }

    std::string inputImageFile = argv[1];
    std::string outputImageFile = argv[2];

    // Load input image
    unsigned char* inputImage;
    int width, height;
    // ...

    // Allocate output image
    unsigned char* outputImage;
    cudaMalloc((void**)&outputImage, width * height * sizeof(unsigned char));

    // Apply filter
    applyFilter<<<dim3(width / 16, height / 16), dim3(16, 16)>>>(inputImage, outputImage, width, height);

    // Save output image
    // ...

    return 0;
}