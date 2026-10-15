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

    int width, height, channels;
    unsigned char* img = stbi_load(image_path.c_str(), &width, &height, &channels, 4);

    if (img == NULL) {
        std::cerr << "Failed to load image";

        stbi_image_free(img);
        return 0;
    }

    if (width > 32) {
        std::cerr << "The image is too big for protogen bawoop";

        stbi_image_free(img);
        return 0;
    }

    unsigned char bitmap[32] = {}; // 5 matrices only lol
    char use_alpha = channels == 4;

    for (int x = 0; x < width; x++) {
        char column = 0x00;

        for (int y = 0; y < 8; y++) {
            int px_idx = (y * width + x) * channels;
            int px_col = img[px_idx];

            if (use_alpha) {
                int px_alpha = img[px_idx + 3];
                px_col &= px_alpha;
            }

            if (px_col > 0) {
                column |= 1 << y;
            }
        }

        bitmap[x] = column;
    }

    stbi_image_free(img);
    return 0;
}