#include <iostream>

#define STB_IMAGE_IMPLEMENTATION
#include "stb/stb_image.h"

int main(int argc, char* argv[]) {
    std::string image_path;

    if (argc == 1) {
        std::cout << "Provide path to image: ";
        std::cin >> image_path;
    } else {
        image_path = argv[1];
    }

    std::cout << image_path;

    return 0;
}